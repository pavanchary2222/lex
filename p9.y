%{
#include<stdio.h>
int yylex();
int yyerror(char *c);
int flag=0;
%}

%token NUM
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
ArithmeticExp:exp '\n' {printf("\nArithmetic_Exp_Val-:%d\n",$$);return 0;};
exp:exp'+'exp {$$=$1+$3;}
	|exp'-'exp {$$=$1-$3;}
	|exp'*'exp {$$=$1*$3;}
	|exp'/'exp {$$=$1/$3;}
	|exp'%'exp {$$=$1%$3;}
	|'('exp')' {$$=$2;}
	|NUM {$$=$1;}
	;

%%
int main(){
printf("Enter the Exp-:");
yyparse();

}
int yyerror(char *c){
printf("%s",c);
}