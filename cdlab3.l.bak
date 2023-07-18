/*lex program to find the length of a string*/

%{
#include<stdio.h>
int length;
int print(int);
%}

/* Rules Section*/
%%
[A]+[a-z A-Z 0-9]+ {length=yyleng; print(length);}
%%
int yywrap(){}



int main()
{
yylex();
//printf("length of given string is : %d", length);
return 0;
}
print(int length)
{
if(length==3)
//if(yytext[0]=='A')printf("string of length 3 :%s",yytext);
return;
}

