%  Auteur : Mohamed TRIA
%  Objectif  : Notion de fenetrage
%  Date : 20/01/2020 
%  Version : 1
clear all;
close all;

load signal 

%=================================================================================%
%=====  Creation d'un signal yr(t) = rect. sin(2pifot)                        =====%
%=================================================================================%

%------------------------------------------------------------------------------------
% Q1. EN UTILISANT LA COMMANDE find, METTRE A 0 TOUS LES ECHANTILLONS SIGNAL > 0.1s

I = find(t > 0.1);

%............
%............

%------------------------------------------------------------------------------------


%------------------------------------------------------------------------------------
% Q2. CONSTRUIRE LA FFT CENTREE Y(f) de y(t)
%..........................



%----  Construction des limites des axes à l'affichage

% limites des axes à l'affichage (temporel) 
tmin = t(1);
tmax = t(N);
ymin = 1.5*min(y);
ymax = 1.5*max(y);

% limites des axes à l'affichage (frequentiel) 
freqmin = fo-30;
freqmax = fo+30;
Ymin = 0;
Ymax = 1.1*max(abs(Y));


%----------------------------------------------------------------------
% Q3a. AFFICHER LE SIGNAL COMPLET SUR UN PREMIER CADRAN 
%     EN UTILISANT LES LIMITES DES AXES tmin, tmax ymin, ymax

%.....................
%.....................
%.....................
%.....................

%-----------------------------------------------------------------------

%-----------------------------------------------------------------------
% Q3b. AFFICHER LE SPECTRE DU SIGNAL SUR UN SECOND CADRAN 
%     EN UTILISANT LES LIMITES DES AXES freqmin, freqmax Ymin, Ymax
%
%.....................
%.....................
%.....................
%.....................

%-----------------------------------------------------------------------


% --- On construit les fenêtres de hamming, hanning et blackman
T = 0.1;
I = find(t<=T);
Ne = max(I);

% on cree les fenêtres de même largeur que la fonction rectangle
ham = hamming(Ne);
han = hanning(Ne);
blk = blackman(Ne);

% on dimensionne les fenêtres de sorte qu'elles soient de même dimension que notre signal temporel

ham = [ham;zeros(N-Ne,1)];
ham = ham.';

han = [han;zeros(N-Ne,1)];
han = han.';

blk = [blk;zeros(N-Ne,1)];
blk = blk.';

%---------------------------------------------------------------------------------------
% Q4. SUPERPOSER LES FENETRES DE  HAMMING, HANNING ET BLACKMAN SUR LE SIGNAL yr(t)
% LIMITES DES AXES : tmin, tmax, ymin, ymax
%........................................
%.........................................
%.........................................
%.........................................
%.........................................
%.........................................
%----------------------------------------------------------------------------------------


%---------------------------------------------------------------------------------------------------
% Q5. APPLIQUER LES DIFFERENTES FENETRES A NOTRE SIGNAL yr(t) EN REALISANT LES OPERATIONS SUVANTES
%     yham = yr x ham; yhan = yr x han ; yblk = yr x blk 
%........................................
%.........................................
%.........................................
%.........................................
%.........................................
%.........................................
%----------------------------------------------------------------------------------------------------

%---------------------------------------------------------------------------------------------------
% Q6. AFFICHER LE SPECTRE DES DIFFERENTS SIGNAUX OBTENUS 
%     CHAQUE SPECTRE SERA NORMALISE DE SORTE QUE SON MAXIMUM SOIT EGAL A 1
%........................................
%.........................................
%.........................................
%.........................................
%.........................................
%.........................................
%----------------------------------------------------------------------------------------------------












