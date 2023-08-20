#include<stdio.h>
#include<ctype.h>
int nprods=0;
char productions[10][10];
void addtoresult(char result[],char c)
{
	int i;
	for(i=0;result[i]!='\0';i++){
	if(result[i]==c)
		return;
	}
	result[i]=c;
	result[i+1]='\0';
}

void First(char* result,char c){
	char subresult[20];
	int foundepsilon=0;
	subresult[0]='\0';
	result[0]='\0';
	if(!isupper(c)){
		addtoresult(result,c);
		return;
	}
	else{
		int i;
		for(i=0;i<nprods;i++){
			if(productions[i][0]==c){
				if(productions[i][2]=='$')
				{
					addtoresult(result,'$');
				}
				else
				{
					int j=2;
					while(productions[i][j]!='\0'){
						foundepsilon=0;
						First(subresult,productions[i][j]);
						int k;
						for(k=0;subresult[k]!='\0';k++){
						addtoresult(result,subresult[k]);}
						for(k=0;subresult[k]!='\0';k++){
							if(subresult[k]=='$')
								foundepsilon=1;
							}
						if(foundepsilon)
							break;
						else
							j++;
					}
				}
			}
		}	
					
	}
return;
}

void main(){
	char choice;
	char c;
	int i,j,k;
	char result[20];
	printf("enter no of productions:");
	scanf("%d",&nprods);
	printf("Enter Productons:");
	for(i=0;i<nprods;i++){
		scanf("%s",productions[i]);
	}

	do{
	printf("Find First:?");
	scanf(" %c",&c);
	printf("First(%c){",c);
	First(result,c);
	for(j=0;result[j]!='\0';j++)
		printf(" %c",result[j]);
	printf("}");
	printf("Enter y for yes and n for no");
	scanf(" %c",&choice);
	}while(choice=='y');
return;
}