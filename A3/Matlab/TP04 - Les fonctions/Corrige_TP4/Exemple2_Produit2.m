clear all;close all;
clc;
%-----------------------------------------------------------------------------------
% EXEMPLES DE L'APPLICATION DE LA FONCTION PRODUIT2  
% NOTION DE VARARGIN et NARGIN 
%
%  Si l'on entre 2 parametres => identique à Produit(a,b)
P1 = 45; P2 = 2 ;
Res = Produit2(P1,P2);
printf("Le resultat du produit vaut : %d\n",Res);



% On rajoute un troisième paramètre
Opt1 = 8;
Res = Produit2(P1,P2,Opt1);
printf("Le resultat du produit vaut : %d\n",Res);


% On rajoute un quatrième paramètre
Opt2 = 25;
Res = Produit2(P1,P2,Opt1,Opt2);
printf("Le resultat du produit vaut : %d\n",Res);


% On peut étendre le nombre d'entrée à l'infini ... et au delà !
Opt = [8 25 47 89 10];
Res = Produit2(P1,P2,Opt(1),Opt(2),Opt(3),Opt(4),Opt(5));
printf("Le resultat du produit vaut : %d\n",Res);
%-----------------------------------------------------------------------------------





