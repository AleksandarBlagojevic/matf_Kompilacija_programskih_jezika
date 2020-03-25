%option noyywrap
%option nounput
%{
#include <iostream>
#include <cstdlib>
#include <cstdio>
  using namespace std;
#include "izraz.hpp"
#include "naredba.hpp"
#include <vector>
#include "parser.tab.hpp"

%}


%%
"pocetak"             return pocetak_token;
"kraj"                return kraj_token;
"ispisi"              return ispisi_token;
"mod"                 return mod_token;
"unesi"               return unesi_token;
"ako_je"              return ako_je_token;
"onda:"               return onda_token;
"inace:"              return inace_token;
"dok_je"              return dok_je_token;
"radi_sledece:"       return radi_sledece_token;
":="                  return dodela_token;
[a-zA-Z_][a-zA-Z0-9_]*   {
  yylval.s = new string(yytext);
  return id_token;
}
[0-9]+                {
  yylval.d = atoi(yytext);
  return num_token;
}
"0x"[0-9A-F]+         {
  sscanf(yytext, "%x", &yylval.d);
  return num_token;
}
\"[^\"]*\"            {
  yylval.s = new string(yytext);
  return string_token;
}
[-+*/();.<>]            return *yytext;
[ \t\n]               {   }
.   {
  cerr << "Neprepoznat karakter '" << *yytext << "'" << endl;
  exit(EXIT_FAILURE);
}
%%


