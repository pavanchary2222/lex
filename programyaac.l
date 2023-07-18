/* Yaac program for desk calculator*/

%{
#include<ctype.h>
#include<stdio.h>
int flag=0;
%}

%token NUMBER
% left '+' '-'
% left '*' '/' '%'
% left '(' ')'

%%
ArithmeticExpression:E{
printf("\n Result=%d\n",$$);
return 0;
}
E : E '+' E { $$=$1+$3;}
| E '-' E {$$=$1-$3;}
| E '*' E {$$=$1*$3;}
| E '/' E {$$=$1/$3;}
| '(' E ')' {$$=$2;}
| NUMBER {$$=$1;}
;
%%

void main(){
printf("\n Enter any Arithmetic Expression which have an operator Add,Sub,Mul,Div,Modulo and rounf brackets\n");
yyparse();
if(flag==0){
printf("\n Entered arithmetic Expression is valid \n");
}
}

void yyerror(){
printf("\n Entered arithmetic Expression is Invalid \n\n");
flag=1;
}