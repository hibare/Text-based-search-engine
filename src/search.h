//SKYNET Inc.
//Discription : Header file for the search engine version beta(v0.1)
//Date : 16.12.2014

#ifndef search_H														//include guards
#define search_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>	//Windows platform
#include<unistd.h>	//Linux platform

int found=0,k1=0,k2=0,fcount=0;											//Global declarations
char dname[10],str[10],word1[10],word2[10];		
FILE *fp;

struct tree
{
	char name[10];
	struct tree *left,*right;
};

typedef struct tree search; 
search *root=NULL;

struct list 															//Defining tree node
{
	char fname[10];
	search *treead;
	struct list *next;
};

typedef struct list node;												//User defined variable
node *list=NULL,*p,*q;

											

//Function prototypes
void dirscan();
void create(char []);
void insert(search *, search *);
void display();
void creattree(char [] );
void sinorder(search *);
void traverse(int );
void dinorder(search *,int );

#endif
