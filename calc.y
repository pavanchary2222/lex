%{
#include<stdio.h>
int flag=0;
%}

%token NUM
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
A:E {printf("\nResult=%d\n",$$);return 0;}
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')'{$$=$2;}
|NUM {$$=$1;}
;
%%

void main(){
printf("Enter Expresion:");
yyparse();
if(flag==0)
	printf("Entered is valid Expression");
return;
}

int yyerror(){
printf("Entered is Invalid Expression");
flag=1;
return 1;
}