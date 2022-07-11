%==================================
% Exercice 1 : Calcul matriciel  
%==================================
clear all;
close all;

%--------------------------------------------------
% Partie 1 - - Résolution d'un système d'équations 
%--------------------------------------------------


% Soit la formulation matricielle Y = AX 

% Q1.  Construire les matrices A et Y 

A = .............;
Y = .............;

% Q2. En déduire la matrice X  des solutions du système d'équation 
X = ...............;

%--------------------------------------------------
% Partie 2  Diagonalisation d'une matrice  et limites
%--------------------------------------------------
n = input("Donner le nombre d'iterations pour calculer D^n et M^n dans une boucle for");
tol = input("Donner la tolerance pour approcher suffisamment la limite de la matrice Mlim : [0.1 / 0.01 / 0.001]");
a = 0.3;b = 0.9; 

% Q1. Construire les matrices S et M 
S = ...................
M = ................


% Q2. Construire D= S^(-1)*M*S et déduire que D est une matrice diagonale

D = .........

##### Méthode n°1  : Construire M^n en passant par la matrice D 
#####                et avec un nombre d'itérations n fixé au départ #######


% On donne temp = D (première itération)
% temp = variable temporelle qui va recevoir D^2, D^3, ... de manière itérative
temp = D; 

% on réitère une même opération dans la boucle for pour construire 
% M^i = S*D^i*S^(-1)

for i = 2 : n

  % Q3. Donner la valeur de temp à chaque itération dans la boucle for 
  %     temp = variable temporelle qui va recevoir D^2, D^3, ... de manière itérative
  temp = ...... 
  
  % D^i
  Di= temp;
  
endfor

% En sortie de la boucle, on a D^n 
Dn_1 = Di; 

% Q4. Construire M^n = S*D^n*S^(-1) [Méthode n°1 : en passant par la matrice D] 
Mn_1 = ..................... 


##### Méthode n°2  : Construire directe de M^n  = M*M*M....*M 
###### jusqu'à approcher suffisamment la limite de la matrice#######

% Q4. Construire valeur limite M_lim = 1/(a+b) [b a; b a;]

M_lim = .............


% à la première itération que l'on fera avant le while
% on a M^1 = M; (normal)
iteration = 1;
temp = M;
Mi_2 = temp;

% Tant qu'on n'a pas suffisamment approché Mlim, on construit M^i
while ( (1/4)*sum(sum(abs(Mi_2-M_lim))) >= tol)

  % Q5. Donner la valeur de temp à chaque itération dans la boucle while
  %     temp = variable temporelle qui va recevoir M^2, M^3, ... de manière itérative 
   
   temp = ......
   % Mi_2 = M^i (avec la méthode n°2)
   Mi_2 = temp;
   iteration = iteration+1; 
  
endwhile

% En sortie de la boucle, on a M^n 

Mn_2 = Mi_2
 
 





