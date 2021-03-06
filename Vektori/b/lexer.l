%option noyywrap
%option nounput

%{
    #include <iostream>
    #include <stdlib.h>

    using namespace std;

    #include "vektor.hpp"

    #include "parser.tab.hpp"

%}

%%
  /* Kljucne reci jezika */
vector                       { return vector_token; }
print                        { return print_token; }
  /* Realni brojevi */
[-]?[0-9]+(\.[0-9]+)?        { 
                                yylval.d= atof(yytext);
                                return num_token;
                             }
  /* Ime vektora pocinje malim slovom za cim sledi eventualno neki broj */
[a-z][0-9]*                  { 
                                yylval.s = new string(yytext); 
                                return id_vektora_token; 
                             }
  /* Jednokarakterski tokeni */
[-+*=,\[\]();]               { return *yytext; }
  /* beline ignorisemo */
[\n\t ]                      {  }
  /* sve ostalo je leksicka greska */
.                            { 
                               cerr<< "Leksicka greska - neprepoznat karakter: " << *yytext <<endl;
                               exit(EXIT_FAILURE);
                             }

%%
