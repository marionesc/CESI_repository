%==========================================================
% Algorithme pour trouver le maximum d'une fonction 
%==========================================================
clear all;
close all;
%--------------------------------------------------------------------------------
% on se propose de trouver de mani�re iterative le maximum de la fonction sinus 
%--------------------------------------------------------------------------------

t= 0:0.1:pi;
y =sin(t);


%  Q1. Afficher la fonction sinus en fonction du temps 
figure(1); 
...................


 #### D�but de l'algorithme pour trouver le maximum de la fonction de mani�re it�rative 
% on fixe la condition d'arr�t des iterations
% si h <= tol, on arr�te l'algorithme
tol = 1e-6;

% On construit l'intervalle de d�part h = [a,b]
a = min(t);
b = max(t);
h = b-a;

% On construit les 2 valeurs � �valuer 
% IL FAUDRA LES METTRE A JOUR DANS LA BOUCLE WHILE 

x1 = a+h/3;
x2= b-h/3;

y_x1 =sin(x1);
y_x2= sin(x2);
 

% Impl�menter l'algorithme 
while (h >= tol) 
  
   ...............
   ...............
   ...............
   ...............
   ...............
   ...............
   ...............
   ...............
   ...............
   

end

% la valeur que l'on recherche est le max entre les 2 valeurs y_x1 et y_x2 
y_max = max(y_x1,y_x2);