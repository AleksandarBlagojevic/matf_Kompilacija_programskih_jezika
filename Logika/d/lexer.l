%option noyywrap
%option nounput

%{
    #include <iostream>
    #include <cstdlib>
    #include <string>
    
    using namespace std;
    
    #include "parser.tab.hpp"
    
%}


%%

[a-z][0-9]*     {   
                    yylval.ime = new string(yytext);
                    return id_token;      
                }

"<=>"           {   return akko_token;    }
\/\\            {   return presek_token;  }
\\\/            {   return unija_token;   }
"=>"            {   return sledi_token;   }

":="            {   return dodela_token;  }
"True"          {
                    yylval.vrednost = 1;
                    return true_token;    
                }
"False"         {   
                    yylval.vrednost = 0;
                    return true_token;    
                }

[!()\n]           {   return *yytext;       }
[ \t]         {   }
.               {
                        cerr << "Leksicka greska - neprepoznat karakter: " << *yytext << endl;
                        exit(EXIT_FAILURE);
                    }

%%
