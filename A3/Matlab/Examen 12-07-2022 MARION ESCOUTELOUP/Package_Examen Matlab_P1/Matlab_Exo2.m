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

format = input("Choisir entre mode demo ou mode projet [0 ou 1] \n");


if format == 0

 % lancement de la fonction filt_num avec ses paramètres par défaut
  filt_num();

elseif format == 1

    SNR = input("Donner le rapport signal a bruit du signal   :  \n");
    ordre = input("Donner l'ordre du filtre moyenneur  :  \n");
    A = input("Donner l'amplitude du signal : \n");
    display = input("Voulez-vous afficher les signaux et le filtre ? Oui [1] /Non [0] \n");

    if display == 0
       % pas d'affichage
       % on récupère en sortie les signaux
       % on utilisera varargout dans le fichier fonction
       [t_outpu0t,signal_output,t,signal_bruit,f,H] = filt_num_corr(SNR,ordre,A,display);

    elseif display == 1

      % lancement de la fonction filt_num avec les paramètres utilisateurs mais sans paramètres en sortie
      filt_num(SNR, ordre, A, display),

    endif

endif







