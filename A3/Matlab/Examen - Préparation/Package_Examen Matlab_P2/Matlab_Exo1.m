
####### Exercice n°1 : dérivation et intégration  ##########
###### On souhaite demander à l'utilisateur le choix d'une fonction y=f(x), 
###### le choix de l'opération à réaliser (dérivation ou intégration)
###### le choix d'une valeur xo pour évaluer soit yf(xo) = f'(xo) [dérivation] soit yf(xo) = F(xo) [intégration]

clear all;
close all;

#### Q1. Définir un vecteur x allant de xmin = 0.1 à xmax = 10 par pas de 0.1
...........................


#### Q2. Implémenter les actions suivantes 

## a. Demander à l'utilisateur la fonction à étudier : 
## Donner la fonction à étudier [Tapez 1 pour y=x^2 ; Tapez 2 pour y=1/x ; Tapez 3 pour y= ln(x)]
................................................

## b. Demander à l'utilisateur 
## Donner l'operation a realiser [Tapez 1 pour dérivation ; Tapez 2 pour intégration] 
...............................................

## c. Demander à l'utilisateur 
## Donner une valeur xo pour calculer soit f'(xo) soit F(xo) 
.................................................

#### Q3. Compléter les lignes ci-dessous en .......

switch (option_y)
  
    case 1
       y = x.^2;  
       fonction = ' y = x^2';

     case 2
      y = 1./x;  
      fonction = ' y = 1/x';
      case 3 
      y = log(x);
      fonction = 'y = ln(x)';

end

switch (option_operation)
  
  
    case 1
       ### Réaliser la dérivée de la fonction y 
       yd = ..............
       
       ### On met à jour la longueur du vecteur x 
       xd = x(1:length(yd)); 
        
       operation = 'derivee';
       
       ### en sortie du switch, une seule fonction yf désignant soit la fonction dérivée de y soit l'intégrale de y 
       yf = yd;
       xf = xd;
       
     case 2
      ### Réaliser l'intégration de la fonction y 
       yi = ..............
       
       ### On met à jour la longueur du vecteur x 
       xi = x(1:length(yi));  
      
       operation = 'primitive';
       
       ### pour la fonction y = ln(x) on ajuste avec un offset (condition initiale)   
       if (strcmp(fonction,' y = 1/x'))
           offset = abs(log(xmin));
           yi = yi-offset;
       endif
       
       ### en sortie du switch, une seule fonction yf désignant soit la fonction dérivée de y soit l'intégrale de y 
       yf = yd;
       xf = xd;    
end

### On recherche l'indice dans le vecteur xf correspondant à la valeur xo
xo_idx = find ( (xo >= xf-dx) & (xo <= xf+dx) );
xo_idx = min(val_idx);



##### Illustrations 

figure;
#### Q4. Superposer sur une figure la fonction y  = f(x) et la fonction yf = f'(x) ou yf = F(x) 
.................................
xlabel('x');
title(['Etude de la fonction  ',fonction,'  Et de sa  ', operation]); 


#### Dans la figure, à la position x=xo, on affiche la valeur de xo et yf(xo) = f'(xo) ou yf = F(xo)

#### Compléter la ligne ci-dessous en .....
if strcmp(operation, 'derivee')
  
     text(xo, yf(xo_idx), ['xo =',num2str(xo),'   ', 'f^\prime(xo) =',num2str(.......)] );

endif

if strcmp(operation, 'primitive')
  
     text(xo, yf(xo_idx), ['xo =',num2str(xo),'   ', 'F(xo) =',num2str(.......)] );

endif




