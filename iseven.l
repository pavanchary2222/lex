%{
#include<stdio.h>
int num=0;
int iseven();
%}

%%
[0-9]* {num=atoi(yytext); iseven();}
%%

int iseven()
{
	if(num%2==0)
	{
		printf("%d is even",atoi(yytext));
	}
	else
	{
		printf("%d is not even",atoi(yytext));
	}
}

int yywrap(){return 1;}

int main(){
printf("Enter number: ");
yylex();
return 0;
}