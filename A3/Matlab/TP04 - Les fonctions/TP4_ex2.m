## Copyright (C) 2022 MARION ESCOUTELOUP
##
## Created: 2022-04-11

function resultat = TP4_ex2(v_a = 1 ,v_b = 1)
  resultat = (v_a .+ v_b);
  
  nb = str2double(inputdlg({'nombre de valeurs supplementaire:'}, ...
                               ' entrée des valeurs utilisateurs', [1 30]))
  for  i = 1 : nb
    value = str2double(inputdlg("entree", ...
                                'valeur supp', [1 30]))
    resultat += value;
  endfor
  display(resultat);
endfunction