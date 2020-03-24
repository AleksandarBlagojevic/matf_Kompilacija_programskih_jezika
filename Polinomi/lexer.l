%option noyywrap
%option nounput

%{
    #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    
    #include "polinomi.hpp"
    
    using namespace std;
    
    #include "parser.tab.hpp"
%}

%%

(-)?[0-9]+(\.[0-9]+)?   {
                            yylval.x = atof(yytext);
                            return num_token;
                        }
                        
[a-z]+[0-9]*            {
                            yylval.s = new string(yytext);
                            return id_token;
                        }
:=                      {   return dodela_token;    }
==                      {   return jednako_token;    }
!=                      {   return razlicito_token;    }
[-+*()<>\n,'|$\[\]]             {   return *yytext; }
[ \t]                   {       }
.                       {
                            cerr <<"Leksicka greska - neprepoznat karakter: " << *yytext << endl;
                            exit(EXIT_FAILURE);
                        }

%%
