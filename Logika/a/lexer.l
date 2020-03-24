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

[a-z]           {   return id_token;      }
"<=>"           {   return akko_token;    }
\/\\            {   return presek_token;  }
\\\/            {   return unija_token;   }
"=>"            {   return sledi_token;   }
[!()]           {   return *yytext;       }
[\n \t]         {   }
.               {
                        cerr << "Leksicka greska - neprepoznat karakter: " << *yytext << endl;
                        exit(EXIT_FAILURE);
                    }

%%
