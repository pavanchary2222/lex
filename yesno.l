%{
#include<stdio.h>
%}

%%
hi | 
HI | 
Hi | 
hI {printf("Bye");}
(.)* {printf("Wrong");}
%%

int yywrap(){return 1;}

int main(){

yylex();
return 0;
}
