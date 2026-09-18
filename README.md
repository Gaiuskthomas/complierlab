Complier Lab
program list
1.lexical analysis
2.dfa
3.epsilon closure

[a-zA-Z][a-zA_Z]* {n++;printf("\tIdentifier: %s\n",yytext);}
"+"|"-"|"*"|"/"|"%"|"="|"<" {n++;printf("\tOperator: %s\n",yytext);}
[(){}|,:;] {n++;printf("\tSpecial Character: %s\n",yytext);}
[0-9]+ {n++;printf("\tInteger: %s\n",yytext);}
[0-9]*"."[0-9]+ {n++;printf("\tFloat: %s\n",yytext);}
%%
int yywrap() {
return 1;
}
int main() {
yyin = fopen("lex.txt", "r");
yylex();
printf("no.of tokens=%d",n);
return 0;
}
