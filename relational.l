%{
#include<stdio.h>
%}

%%
"<" |
">" |
"<=" |
">=" |
"==" |
"!=" {printf("is a relational operator");}
(.*) {printf("is not a Relational operator");}
%%

int yywrap(){return 1;}

int main(){
printf("Enter number: ");
yylex();
return 0;
}