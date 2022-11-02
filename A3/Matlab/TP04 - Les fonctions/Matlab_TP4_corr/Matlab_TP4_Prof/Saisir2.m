function [varargout] = Saisir2()

for i=1:nargout
  if i==1 
     varargout{i} = input("Entrez la frequence d'echantillonnage : ");
  end

  if i==2
     varargout{i} = input("Entrez la frequence du signal : ");
  end
  
  if i==3
     varargout{i} = input(" Entrer le nombre d'echantillons : ");
  end
  
  if i==4
     varargout{i} = input("Entrez la duree du signal  : ");
  end
    
end
end
