##
## DOCUMENT REMPLI PAR MARION ESCOUTELOUP
##    GitHub : maresc
##
##  12/07/2022
##
##  Cours CESI - FIPA 26 S3E
##  Matlab & Octave

clear all;
close all;

% Dans ce 3ème exercice, on se propose de concevoir l'arbre de Huffman
% et de mettre en évidence la pertinence de l'algorithme pour la compression de données

load data;

# Chargement de la data
% h 1
% j 1
% n 1
% l 2
% i 3
% m 4
% a 8

% L a première colonne donne les caractères
% la seconde colonne donne le nombre d'apparition du caractère concerné
% EXEMPLE :
% stats(1,1) donne h
% stats(1,2) donne 1 :  h apparait effectivement une seule fois dans la phrase etudiee
% ATTENTION  : ICI le nombre d'apparition est de type chaine
%            : pour toute operation arithmetique, il faut convertir eh nombre
%            : avec str2num()


% Q1. Calculer la taille en bits du fichier (c'est  à dire de la phrase en fait)
%     avec la formule SC = nombre de bits x nombre de lettres total dans la phrase
%     nombre de caracteres doit être déduits à partir de la variable stats (suite au chargement de la data)
%     en utilisant sum() et str2num()

nbits = 3;
nb_lettres_total = 20;

SC =  nbits * nb_lettres_total;

printf("La taille du fichier est %d bits\n",SC);



% Chargement de l'arbre

load data_Arbre;
% Arbre =
% h1g
% j1d
% n2g
% l3g
% i4g
% m5g
% a6g

% La première colonne donne les caractères
% la seconde colonne donne le niveau dans l'arbre (en partant du bas de l'arbre) du caractère concerné
% La troisième colonne indique si la branche est à gauche ou à droite
% EXEMPLE :
% Arbre(1,1) indique le caractère 'h'
% Arbre(1,2) indique qu'on se situe au 1er niveau dans l'arbre
% Arbre(1,3) indique que la branche est à gauche


% ATTENTION  : ICI le niveau est de type type chaine
%            : pour toute operation arithmetique, il faut convertir eh nombre
%            : avec str2num()


% initiation de l'indice caractère
% idx_car = 1 indique qu'on traite d'abord le caractère 'h'
% idx_car = 2 indique qu'on traitera le caractere 'j'
% ect ...
% jusqu"à idx_car = 7 qui indique le caractere 'a'
idx_car = 1;
niveau_arbre_total = 6; % nombre de niveaux total de l'arbre
nbcar_total = 7; % nombre de caracteres 'h' 'j' 'n' 'l' 'i' 'm' 'a'


% Q2. Compléter la boucle while () en intégrant les lignes permettant d'affecter les codes pour les caracteres
%     se situant sur les niveaux 2,3,4 et 5

while (idx_car <= nbcar_total)  % on balaye les lignes de l'Arbre, c'est a dire les caractères de 'h' à 'a'

    % si le niveau est de 1
    if (str2num(Arbre(idx_car,2)) == 1)

         % si la branche est à gauche, on attribue le code '111110'
         if (strcmp(Arbre(idx_car,3),'g'))
           code{idx_car} = '111110';

           % apres affectation du code, on passe au caractere suivant pour connaitre son code
           idx_car = idx_car+1;
         elseif (strcmp(Arbre(idx_car,3),'d'))

           % si la branche est à droite, on attribue le code '111111'
           code{idx_car} = '111111';
           % apres affectation du code, on passe au caractere suivant pour connaitre son code
           idx_car = idx_car+1;
       endif
    endif

   %  Intégration des lignes permettant d'affecter les codes pour les caracteres
   %  se situant sur les niveaux 2,3,4 et 5
   % Niveau 2
   if (str2num(Arbre(idx_car,2)) == 2 )
     if (strcmp(Arbre(idx_car,3),'g'))
       code{idx_car} = '11110';
       idx_car += 1;
     elseif (strcmp(Arbre(idx_car,3),'d'))
       code{idx_car} = '11111';
       idx_car += 1;
    endif
   endif


    % Niveau 3
   if (str2num(Arbre(idx_car,2)) == 3 )
     if (strcmp(Arbre(idx_car,3),'g'))
       code{idx_car} = '1110';
       idx_car += 1;
     elseif (strcmp(Arbre(idx_car,3),'d'))
       code{idx_car} = '1111';
       idx_car += 1;
    endif
   endif

 % Niveau 4
   if (str2num(Arbre(idx_car,2)) == 4 )
     if (strcmp(Arbre(idx_car,3),'g'))
       code{idx_car} = '110';
       idx_car += 1;
     elseif (strcmp(Arbre(idx_car,3),'d'))
       code{idx_car} = '111';
       idx_car += 1;
    endif
   endif

 % Niveau 5
   if (str2num(Arbre(idx_car,2)) == 5 )
     if (strcmp(Arbre(idx_car,3),'g'))
       code{idx_car} = '10';
       idx_car += 1;
     elseif (strcmp(Arbre(idx_car,3),'d'))
       code{idx_car} = '11';
       idx_car += 1;
    endif
   endif


    % si le niveau est de 6
    if (str2num(Arbre(idx_car,2)) == 6)
         if (strcmp(Arbre(idx_car,3),'g'))
           code{idx_car} = '0';
           idx_car = idx_car+1;
         elseif s(strcmp(Arbre(idx_car,3),'d'))
           code{i} = '1';
           idx_car = idx_car+1;
         endif
    endif
end


% Q3. Calculer la taille du fichier apres compression
% length(code{i}) donne la taille en bits du code du caractère n°i
% on récupère le nombre d'apparition du caractère n°i à partir de stats (utiliser str2num() pour une conversion en numérique)
AC = 0;
for i = 1 : nbcar_total
  AC = AC + str2num(stats(i,2))*length(code{i});
endfor


printf("La taille du fichier est %d bits\n",AC);

% Q4.Completer la ligne ci-dessous pour avoir le taux de compression
taux_compression = (1 - (AC/SC))*100;
printf("Le taux de compression est de %d %% \n", taux_compression);

