%{
	int vow_count=0;
	int const_count=0;
%}

%%
[aeiouAEIOU]{vow_count++;}
[a-z A-Z]{const_count++;}
%%
int yywrap(){}
int main()
{
	printf("Enter the string of vowels&Consonants");
	yylex();
	printf("noof vowels =%d\n no of consonants=%d",vow_count,const_count);
	return 0;
}