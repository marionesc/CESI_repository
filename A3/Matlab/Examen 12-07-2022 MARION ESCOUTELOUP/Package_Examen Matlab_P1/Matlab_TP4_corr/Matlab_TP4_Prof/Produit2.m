
% Notion de varargin
% varargin est une sorte d'entr�es optionnelles 

function res = Produit2(a,b,varargin)
  
  printf("Le nombre de parametres en entree est %d \n",nargin);
  
  res = a*b;
  
  % � chaque fois qu'on ajoute un parametre optionnel, 
  % il est multiplier � res
  for i = 1 : length(varargin)
     res = res * varargin{i};
  end
 
endfunction
