%{
#include<stdio.h>

int num=0;
int deci=0;
%}

%%
[0-9]+"."[0-9]+ {ECHO;printf("%s is decimal ",yytext);deci++;}
[0-9]+ {ECHO; printf("%s is integer ",yytext);num++;}
%%

int main()
{
	printf("Enter numbers: ");
	yylex();
	printf("Decimal count=%d, Num count=%d",deci,num);
	retutn 0;
}
int yywrap()
{return 1;
}