//SKYNET Inc.
//Discription : File with function definations (search engine version beta(v0.1))
//Date : 16.12.2014

#include "search.h"

void dirscan()															//Function defination for directory scanning specified by the user
{
	DIR *d;
	struct dirent *dir;
	d=opendir(dname);
	if(d==NULL)
	{
		printf("ERROR... Unable to open the directory\nIndexing failed\n"
		"Terminating the program\n\n");
		exit(0);
	}
	if(d)
	{
		while((dir=readdir(d)) != NULL)
		{
			if((strcmp(dir->d_name,".") == 0) ||(strcmp(dir->d_name,"..") == 0))	//Excluding current directory(.) and parent directory(..)
				continue;
			fcount++;
			create(dir->d_name);										//Initiating tree creation
		}
		
		closedir(d);
	}
	return;
}

void create(char fdname[] )												//Creating index nodes to the rest of the tree
{
	if(list==NULL)
	{
		list=(node *)malloc(sizeof(node));
		if(list==NULL)
		{
			printf("ERROR...Memory allocation problem\n"
			"Terminating the program\n\n");
			exit(0);
		}
		
		q=list;
		
	}
	else
	{
		p=list;
		q=list;
		while(p!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=(node *)malloc(sizeof(node));
		if(q->next==NULL)
		{
			printf("ERROR...Memory alocation problem\n"
			"Terminating the program\n\n");
			exit(0);
		}
		q=q->next;
		
	}
	strcpy(q->fname,fdname);
	q->next=NULL;
	chdir(dname);														//Changing directry to the directory conaining the files as to access individual files
	fp=fopen(fdname,"r");
	if(fp==NULL)
	{
		printf("ERROR...Unable to open the file\n");
		return;
	}
	while((fscanf(fp,"%s",str)) != EOF)
	{
		creattree(str);
	}
	q->treead=root;														//Storing the address of the tree in respective nodes
	root=NULL;															//Initialising root to null for next tree creation
	chdir("..");														//Changing to parent directory to scan for next avilable file
	return;
}
	
void creattree(char str[] )												//Function defination for binary search tree creation
{
	search *new;
	new=(search *)malloc(sizeof(search));
	if(new==NULL)
	{
		printf("Memory allocation error\n");
		exit(0);
	}
	new->left=NULL;
	new->right=NULL;
	strcpy(new->name,str);
	
	if(root==NULL)
	{
		root=new;
	}
	else
	{
		insert(root,new);
	}
	
	return;
}

void insert(search *root,search *new)									//Locating search(node) insertion location in the tree 
{
	
	if(new->name < root->name)
	{
		if(root->left==NULL)
		{
			root->left=new;
		}
		else
		{
			insert(root->left,new);
		}
	}
	
	if(new->name >= root->name)
	{
		if(root->right==NULL)
		{
			root->right=new;
		}
		else
		{
			insert(root->right,new);
		}
	}
	return;
}
	
void display()															//Displaying the list of files scanned from the directory specified by the user
{
	if(list==NULL)
	{
		printf("ERROR...Data not found\n"
		"Terminating program\n\n");
		exit(0);
	}
	p=list;
	while(p!=NULL)
	{
		printf("%s\n",p->fname);
		p=p->next;
	}
	puts("\n");
	return;
}

void traverse(int ch1)													//Traversing list to access individual tree linked with respective file names
{
	if(list==NULL)
	{
		printf("ERROR...Data not found\n"
		"Terminating the program\n\n");
		exit(0);
	}
	p=list;
	while(p!=NULL)
	{
		if(ch1==1)
			sinorder(p->treead);										//Function call for individual word search
		if(ch1==2 || ch1==3)
			dinorder(p->treead,ch1);									//Function call for two words search 
		k1=0;k2=0;														//Resetting flags for next tree scan
		
		p=p->next;
	}
	return;
}

void sinorder(search *temp)												//Function defination for individual word search
{
	if(temp!=NULL)
		{
			sinorder(temp->left);
			{
				if((strcmp(temp->name,word1)) == 0)
				{
					found=1;
					printf("Match found in file : %s\n",p->fname);
					return;
				}
			}
			sinorder(temp->right);
		}
	return;
}
	
void dinorder(search *temp,int ch1)										//Function defination for two words search
{
	if(temp!=NULL)
	{
		dinorder(temp->left,ch1);
		switch(ch1)
		{
			case 2: if(k1==0)											//AND logic search
					{
						if((strcmp(temp->name,word1)) == 0)
							k1=1;
					}
					if(k2==0)
					{
						if((strcmp(temp->name,word2)) == 0)
							k2=1;
					}
					
					if((k1==1) && (k2==1))
					{
						found=1;
						printf("Word match found in file %s\n",p->fname);	//Printing file name if both the words are present in the perticular file(tree)
						return;
					}
					break;
			
		case 3 : if(k1==0)												//OR logic search
					{
						if((strcmp(temp->name,word1)) == 0)
						{
							k1=1;
						}
					}
					if(k2==0)
					{
						if((strcmp(temp->name,word2)) == 0)
						{
							k2=1;
						}
					}
					if((k1==1) || (k2==1))
					{
						printf("Word match found in file %s\n",p->fname);	//Printing file name if any of the word present in the file(tree)
						found=1;
						return;
					}
					break;
		}
	dinorder(temp->right,ch1);
	}
	return;
}
