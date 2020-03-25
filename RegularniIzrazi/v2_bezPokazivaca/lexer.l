%option noyywrap
%option nounput

%{
  #include <iostream>
  #include <cstdlib>
  #include <cstdio>
  
  using namespace std;
  
  #include "regex.hpp"
  
  #include "parser.tab.hpp"

%}

%%

BASIC			return basic_token;
DEFINITION		return definition_token;
MAXLEN			return maxlen_token;

[A-Z]			{
				yylval.c = *yytext;
				return id_token;
			}
[a-z]			{
				yylval.c = *yytext;
				return slovo_token;
			}
[0-9]+			{
				yylval.d = atoi(yytext);
				return num_token;
			}

[+*.{}()|?\[\]\n=,]	return *yytext;

[ \t]			{ 	}

.			{
				cerr << "Leksicka greska - neprepoznat karakter: " << *yytext << endl;
				exit(EXIT_FAILURE);
			}

%%