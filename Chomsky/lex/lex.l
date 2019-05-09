%{
 #include <string.h>
 int  szamok_szama =0;
%}
%% 		
[0-9]+		{++szamok_szama;}
			


%%

int 
main()
{
 yylex();
 printf("%d szam\n",szamok_szama); 							
return 0;

}
