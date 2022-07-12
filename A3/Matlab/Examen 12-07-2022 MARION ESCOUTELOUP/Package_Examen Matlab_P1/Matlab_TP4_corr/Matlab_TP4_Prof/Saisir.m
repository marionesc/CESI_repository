function [varargout] = Saisir()
   
   printf('Saisie de %d valeurs \n \n',nargout);
   
   for i=1:nargout % nombre de parametres en sortie
     varargout{i} = input("Entrez une valeur : ");
   end
  
endfunction 

