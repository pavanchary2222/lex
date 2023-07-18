#include<stdio.h>
#include<string.h>
#include<ctype.h>
int n,m=0,i=0,j=0;
char a[10][10],result[10];
void follow(char c);
void first(char c);
void addtoresult(char);
void main()
{
	int i;
	int choice;
	char c;
	printf("enter no of productions");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter p%d :",i+1);
		scanf("%s",a[i]);
	}
	do{
		m=0;
		printf("enter character :");
		scanf(" %c",&c);
		follow(c);
		printf("{");
		for(i=0;i<m;i++)
			printf("%c ",result[i]);
			printf("}\n");
			printf("enter 1 :");
			scanf("%d",&choice);
	}
	while(choice==1);
	
}
void follow(char c)
{
	if(a[0][0]==c)addtoresult('$');
	for(i=0;i<n;i++)
	{
		for(j=2;j<strlen(a[i]);j++)
		{
			if(a[i][j]==c){
				if((a[i][j+1])!='\0')
					first(a[i][j+1]);
				if(a[i][j+1]=='\0')
					follow(a[i][0]);	
			}
		}
	}
}
void first(char c)
{
	int k;
	if(!(isupper(c)))
		addtoresult(c);
	for(k=0;k<n;k++)
	{
		if(a[k][0]==c)
		{
			if(a[k][2]=='$')
				follow(a[k][0]);
			else if(islower(a[k][2]))
				addtoresult(a[k][2]);
			else
				first(a[k][2]);
		}
	}
}
void addtoresult(char c)
{
	int i;
	for(i=0;i<=m;i++)
		if(result[i]==c)
			return;
  	result[m++]=c;
}

/*
S-aABb
A-c
A-$
B-d
B-$
*/