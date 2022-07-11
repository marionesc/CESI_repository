
####### Exercice n�1 : d�rivation et int�gration  ##########
###### On souhaite demander � l'utilisateur le choix d'une fonction y=f(x), 
###### le choix de l'op�ration � r�aliser (d�rivation ou int�gration)
###### le choix d'une valeur xo pour �valuer soit yf(xo) = f'(xo) [d�rivation] soit yf(xo) = F(xo) [int�gration]

clear all;
close all;

#### Q1. D�finir un vecteur x allant de xmin = 0.1 � xmax = 10 par pas de 0.1
...........................


#### Q2. Impl�menter les actions suivantes 

## a. Demander � l'utilisateur la fonction � �tudier : 
## Donner la fonction � �tudier [Tapez 1 pour y=x^2 ; Tapez 2 pour y=1/x ; Tapez 3 pour y= ln(x)]
................................................

## b. Demander � l'utilisateur 
## Donner l'operation a realiser [Tapez 1 pour d�rivation ; Tapez 2 pour int�gration] 
...............................................

## c. Demander � l'utilisateur 
## Donner une valeur xo pour calculer soit f'(xo) soit F(xo) 
.................................................

#### Q3. Compl�ter les lignes ci-dessous en .......

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
       ### R�aliser la d�riv�e de la fonction y 
       yd = ..............
       
       ### On met � jour la longueur du vecteur x 
       xd = x(1:length(yd)); 
        
       operation = 'derivee';
       
       ### en sortie du switch, une seule fonction yf d�signant soit la fonction d�riv�e de y soit l'int�grale de y 
       yf = yd;
       xf = xd;
       
     case 2
      ### R�aliser l'int�gration de la fonction y 
       yi = ..............
       
       ### On met � jour la longueur du vecteur x 
       xi = x(1:length(yi));  
      
       operation = 'primitive';
       
       ### pour la fonction y = ln(x) on ajuste avec un offset (condition initiale)   
       if (strcmp(fonction,' y = 1/x'))
           offset = abs(log(xmin));
           yi = yi-offset;
       endif
       
       ### en sortie du switch, une seule fonction yf d�signant soit la fonction d�riv�e de y soit l'int�grale de y 
       yf = yd;
       xf = xd;    
end

### On recherche l'indice dans le vecteur xf correspondant � la valeur xo
xo_idx = find ( (xo >= xf-dx) & (xo <= xf+dx) );
xo_idx = min(val_idx);



##### Illustrations 

figure;
#### Q4. Superposer sur une figure la fonction y  = f(x) et la fonction yf = f'(x) ou yf = F(x) 
.................................
xlabel('x');
title(['Etude de la fonction  ',fonction,'  Et de sa  ', operation]); 


#### Dans la figure, � la position x=xo, on affiche la valeur de xo et yf(xo) = f'(xo) ou yf = F(xo)

#### Compl�ter la ligne ci-dessous en .....
if strcmp(operation, 'derivee')
  
     text(xo, yf(xo_idx), ['xo =',num2str(xo),'   ', 'f^\prime(xo) =',num2str(.......)] );

endif

if strcmp(operation, 'primitive')
  
     text(xo, yf(xo_idx), ['xo =',num2str(xo),'   ', 'F(xo) =',num2str(.......)] );

endif




