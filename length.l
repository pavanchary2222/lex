%{
#include<stdio.h>
int len;
%}

%%
. {len+=yyleng;}
\n {return 0;}
"end" {return 0;}
%%

int yywrap(){return 1;}

int main(){
printf("Enter string: ");
yylex();
printf("The length is:%d",len);
return 0;
}