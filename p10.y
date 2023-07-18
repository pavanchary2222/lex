%{
#include<stdio.h>
int yylex();
int yyerror(char *c);
%}

%token NUM
%left '+' '-'
%left '*' '/'
%left '(' ')'
%right NEGATIVE
%%
ArithEval:exp '\n' {printf("\n");};
exp:exp'+'exp {printf("+");}
	|exp'-'exp {printf("-");}
	|exp'*'exp {printf("*");}
	|exp'/'exp {printf("/");}
	|'('exp')'
	|NUM {printf("%d",yylval);}
	;
%%

int main(){
printf("Enter the Exp-:");
yyparse();
return 0;
}
int yyerror(char *c){
printf("%s",c);
}
