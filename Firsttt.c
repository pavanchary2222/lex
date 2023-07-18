#include<stdio.h>
#include<ctype.h>
char production[10][10];
int n;
void first(char[],char);
void addtoresult(char[],char);
int main()
{
	
	char choice;
	char c;
	char result[10];

	printf("enter no of productions");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		printf(" %d ",i+1);
		scanf("%s",production[i]);
	}
	do{
		printf("enter first of character");
		scanf(" %c",&c);
		first(result,c);
		printf("first (%c)={",c);
		for(i=0;i<result[i]!='\0';i++)
			printf("%c ",result[i]);
			printf("}\n");
			printf("enter y to next first");
			scanf(" %c",&choice);
	}
	while(choice=='y' || choice=='Y');
}
void first(char *result,char c)
{
	int i,j,k;
	char subresult[10];
	int foundepsilon;
	subresult[0]='\0';
	result[0]='\0';
	if(!(isupper(c)))
	{
		addtoresult(result,c);
		return;
	}
		for(i=0;i<n;i++)
	{
		if(production[i][0]==c)
		{
			if(production[i][2]=='$')
				addtoresult(result,'$');
			else
			{
				j=2;
				while(production[i][j]!='\0')
				{
					foundepsilon=0;
					first(subresult,production[i][j]);
					for(k=0;subresult[k]!='\0';k++)
						addtoresult(result,subresult[k]);
					for(k=0;subresult[k]!='\0';k++)
						if(subresult[k]=='$')
							foundepsilon=1;
							break;
						if(!foundepsilon)
							break;
						j++;
				}
			}
		}
	}
	return;
}
void addtoresult(char result[],char c)
{
	int i;
	for(i=0;result[i]!='\0';i++)
	{
	     if(result[i]==c)
		 {
		 	return;
		 }	
	}
	result[i]=c;
	result[i+1]='\0';
 } 
 
 
 
 /*
 S-aABb
 A-c
 A-$
 B-d
 B-$
 */
