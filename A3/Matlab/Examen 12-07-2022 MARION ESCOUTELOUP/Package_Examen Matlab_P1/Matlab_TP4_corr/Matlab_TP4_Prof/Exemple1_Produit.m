%-----------------------------------------------------------------------------------
% EXEMPLES DE L'APPLICATION DE LA FONCTION PRODUIT  
clear all;
close all;
% meme nom des parametres et variables locales : A EVITER !
a = 45; b = 2;
res = Produit(a,b);
printf("Le resultat du produit vaut : %d\n",res);


##% nom de parametres et variables locales differentes : RECOMMANDE
Jayson = 4; Laurie = 5;
Gaetan = Produit(Jayson,Laurie); % sous entend qu'à l'intérieur de la fonction a<--A b<--B
 
 
 %  res calculé --> C 
%printf("Le resultat du produit vaut : %d\n",Gaetan);
##
##% nom de parametres et variables locales differentes : RECOMMANDE
##D = 56; E = 3;
##F = Produit (D,E);
##printf("Le resultat du produit vaut : %d\n",F);
%-----------------------------------------------------------------------------------


%------------------------------------------------------------------------------------
% DERNIER EXEMPLE 
% je definis mes variables locales à l'exterieur de ma fonction
%Theo = 5;
%Brice = 10;
a = 6;
b = 7;
% ma variable res initialisée à 0
res = 0; 

% sous entendu que ma fonction va reconnaître les variables a et b definies au dessus
res = Produit();


return


% a <-- ??  b<-- ?? => les variables locales sont "vides" de valeurs
% La fonction ne reconnaît pas les variables a,b définies en dehors de la fonction

%--------------------
%error: 'a' undefined near line 4 column 9
%error: called from
%    Produit at line 4 column 7
%    Exemple1_Produit at line 31 column 5
%---------------------
% TRADUCTION : La fonction Produit() attend qu'on entre les parametres 
%              qui vont DONNER VIE A SES VARIABLES LOCALES