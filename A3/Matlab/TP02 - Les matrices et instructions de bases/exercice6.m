## EXERCICE 6 :  Programmes simples utilisant la bouvle for et la condition if


clear; 
clc; 

display("TP2 - Exercice 6 ");

function nombrePaire = afficherNombrePaire(nbMax)
  display("nombre paire : ");
  for i = 0 : nbMax 
    if (i - 2 .*  floor(i ./ 2)) == 0
      disp(i)
    endif
  endfor
endfunction

function pariteNb = pariteDuNombre(i)
  if (i - 2 .*  floor(i ./ 2)) == 0
    display ("Le nombre", i, "est paire") 
  endif
  if (i - 2 .*  floor(i ./ 2)) != 0
    display ("Le nombre", i, "est impaire") 
  endif
endfunction