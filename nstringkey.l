%{
int lines=0;
int words=0;
int ch=0;
int space=0;
%}


%%
[\n] {lines++, ch+=yyleng;}
[ \t] {space++, ch+=yyleng;}
[^\t\n ]+ {words++, ch+=yyleng;}
%%

int main(){
printf("Enter string or keyword");
yylex();
printf("lines =%d, words=%d, characters=%d,spaces=%d",lines,words,ch,space); 
return 0;
}

int yywrap(){
return 1;
}