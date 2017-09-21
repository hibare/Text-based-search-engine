//SKYNET Inc.
//Discription : main file for search engine version beta(v0.1)
//Date : 16.12.2014

#include "search.h"
#include "19050118030803.c"

int main()
{														
	int ch1;															//Local declarations
	char ch2;
	
	printf("Please enter the directory name : ");
	scanf(" %[^\n]s",dname);											//Reading directory name
	chdir("..");														//Change directory to parent directory
															
	printf("---------------------------------------------------------------------------\n\n");
	printf("Initiate directory scanning and indexing <y/n>?? ");		//Prompt to initiate directory scanning and indexing
	scanf(" %c",&ch2);
	puts("\n");
	if(ch2=='y' || ch2=='Y')
		dirscan();
	else
	{
		printf("ERROR.....Uninitiated directory scanning and indexing\n"
		"Terminating program\n\n");
		exit(0);
	}
	
	printf("---------------------------------------------------------------------------\n\n");
	printf("Please verify the file names :\n\n");
	printf("Number of files detected : %d\nDetected file are : \n",fcount);
	display();															//Printing tree content
	printf("----------------------------------------------------------------------------\n\n");
	
	printf("Initiate search <y/n>?? ");									//Prompt to initiate search
	scanf(" %c",&ch2);
	puts("\n");
	if(ch2=='n' || ch2=='N')
	{
		printf("Warning!!!.. Search is not initiated\n"
		"Terminating program\n\n");
		exit(0);
	}
	else
	{
		do
		{
			printf("Press\n");											//Menu for search
			printf("1: Simple word search\n2: AND logic search\n3: OR logic search\nEnter your choice :");
			scanf("%d",&ch1);
			puts("\n");
			switch(ch1)
			{
				case 1: printf("Enter the word to be searched <[word]> : ");
						scanf(" %s",word1);
						traverse(ch1);
						if(found==0)
							printf("Match not found in any file\n");
						found=0;
						break;
						
				case 2: printf("Enter the words to be searched <[word1][space][word2]> : ");
						scanf(" %s%s",word1,word2);
						traverse(ch1);
						if(found==0)
							printf("Match not found in any file\n");
						found=0;
						break;
						
				case 3: printf("Enter the words to be searched <[word1][space][word2]> : ");
						scanf(" %s%s",word1,word2);
						traverse(ch1);
						if(found==0)
							printf("Match not found in any file\n");
						found=0;
						break;
				
				default : printf("Invalid choice.. Please try again\n");
						  break;
			}
			printf("----------------------------------------------------------------------------\n\n");
			printf("Restart search <y/n>??");							//prompt to restart the search
			scanf(" %c",&ch2);
		}while(ch2=='y' || ch2=='Y');
	}
	printf("Thank you\n\n");
	printf("----------------------------------------------------------------------------\n");
	return 0;

}
