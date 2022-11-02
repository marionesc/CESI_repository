function res = Horner();
  
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
xo = input("Donner xo pour evaluer P(xo) : ");

a = zeros(1,n);

for i = n:-1:1
   
   a(i) =input(["Donner le coefficient a",num2str(i)," : "]);
   
   if (i==n)
        temp = a(i);
   endif
   
   if (i<n)
     temp = temp*xo+a(i);
   endif
 
endfor

ao = input("Donner le coefficient ao : ");

res = temp*xo + ao;


