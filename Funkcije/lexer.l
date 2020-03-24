%option noyywrap
%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include "function.hpp"
using namespace std;

/* Ukljucujemo zaglavlje u kome su definisani tokeni */
#include "parser.tab.hpp"

%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
value                       { return value_token; }
sqrt                        { return sqrt_token; }
sin                         { return sin_token; }
cos                         { return cos_token; }
function                    { return function_token; }
[a-wyz]                     { yylval.s = new string (yytext); return id_token; }
x                           { return x_token; } 
{DIGIT}+(\.{DIGIT}*)?   {
                                 /* Postavljamo atribut tokena na procitanu vrednost
                                  * ali sada je yylval unija, pa moramo reci koje polje unije postavljamo
                                  */
                                 yylval.x = atof(yytext);
                                 return num_token;
                            }
[+\-*/()"=\'\[\]\n]         {  return *yytext; }
[ \t]                     { }
.                           {
                               fprintf(stderr, "Leksicka greska: Nepoznat karakter %c\b", *yytext);
                               exit(EXIT_FAILURE);
                            }

%%
