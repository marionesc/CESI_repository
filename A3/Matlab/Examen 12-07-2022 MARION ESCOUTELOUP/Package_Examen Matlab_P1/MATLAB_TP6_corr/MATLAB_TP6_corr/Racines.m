function res = Racines();
  
%============================================================================%
% FONCTION RETOURNANT P(xo) [Polynome de degre n]   
% res = Horner()
%
% ENTREES 
% aucune
%
% 
% SORTIE
% res : P(xo)
%
% EXEMPLES 
% 
% Pxo = Horner();
%
%
%===================================================================%

n = input("Donner l'ordre du polynome : ");

a = zeros(1,n);

for i = n:-1:1
   
   a(i) =input(["Donner le coefficient a",num2str(i)," : "]);
   
  
endfor

ao = input("Donner le coefficient ao : ");

% vecteur des coefficients
p = [a ao];

res = roots(p);

