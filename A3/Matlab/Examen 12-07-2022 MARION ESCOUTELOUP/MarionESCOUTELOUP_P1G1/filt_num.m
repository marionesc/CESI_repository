##
## DOCUMENT REMPLI PAR MARION ESCOUTELOUP
##    GitHub : maresc
##
##  12/07/2022
##
##  Cours CESI - FIPA 26 S3E
##  Matlab & Octave

##### Exercice n°2  : traitement du signal et filtrage numérique #######

% Q1. Compléter l'entête ci-dessous pour déclarer la fonction filt_num

function filt_num(SNR , ordre, A, display)

 % chargement des donnees signal
 load data_signal;

 % Obtention de la longueur du signal
 N = length(signal);

 % Obtention de la fréquence d'échantillonnage Fe à partir de la variable t
 % Rappel : Fe = 1/Te. Te étant l'intervalle entre 2 échantillons de temps

 Fe = 1/t(3);


  % Filtrage

  % Si pas de paramètres en entrée de la fonction filt_num
  % paramètres par défaut
  if (nargin == 0)
    % les valeurs par défaut
   SNR = 15;   % rapport signal à bruit
    ordre = 5;  % ordre du filtre numérique
    A = 1;      % amplitude
    display = 1;

  else
   SNR = SNR;
   ordre = ordre;
   A = A;
   display = display;

  end

  sigma = sqrt((A^2/2)*10^(-SNR/10));
  bruit = sigma*rand(1,N);
  signal_bruit = A*signal + bruit;


  % Filtre

  A = 1;
  B = (1./ordre).*ones(1,ordre);

  [H,f] = freqz(B,A,Fe);


  % f donner entre [0,pi] => normalisation de f entre [0,Fs/2]

  f = f*Fe/(2*pi);

  signal_output= filter(B,A,signal_bruit);
  N_output = length(signal_output);
  t_output = 0 :(1/Fe): (N_output-1)*(1/Fe);

  if display ==1
   figure;
   #### Affichage des resultats actif ####

   %--- Sur premier cadran (utiliser subplot) :
   %    Module du filtre H en decibels en fonction de la fréquence
   subplot(2,1,1)
   plot(f, 20*log10(abs(H)));
   title("Module du filtre H ");
   xlabel("x : frequence");
   ylabel("y : decibels");


   %--- Sur deuxième cadran (utiliser subplot) :
   %     superposition du signal avant filtrage et après filtrage
   %     label en x : temps
   %     titre : signaux avant et après filtrage
   subplot(2,1,2)
   plot(t_output, signal*A, 'r');
   hold on
   plot(t_output, signal_output,'b');
   title("Signaux avant et apres filtrage");
   xlabel("x : temps");
  legend("Avant filtrage", "après filtrage");


  elseif display == 0

    %[t_output,signal_output,t,signal_bruit,f,H]
   varargout{1} = t_output;        % t_output
   varargout{2} = signal_output;   % signal_output
   varargout{3} = t;               % t
   varargout{4} = signal_bruit;    % signal_bruit
   varargout{5} = f;               % f
   varargout{6} = H;               % H

  endif




