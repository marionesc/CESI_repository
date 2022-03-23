%  Auteur : Mohamed TRIA
%  Objectif  : Algorithme rapide de Fourier et FFTSHIFT
%  Date : 20/01/2020 
%  Version : 1
clear all;
close all;

%---- Chargement du signal et des parametres
load signal


%====================================================================%
%=====  Centrage du spectre  Y(f) autour de freq = 0hz          =====%
%====================================================================%

%--- Centrage du spectre autour de freq = 0 hz  = [-Fe/2 Fe/2]

% ==> fonction fftshift = Le cadran [Fe/2 Fe] est déporté à gauche et devient [-Fe/2 0]
%                Le cadran [0 Fe/2] est déporté à droite et reste à [0,Fe/2] 

%---------------------------------------------------------------------------
% Q1. CENTRER LE SPECTRE DU SIGNAL SUR [-Fe/2 Fe/2]
 
%...................
%...................

%----------------------------------------------------------------------------


%----  Construction des limites des axes à l'affichage

% limites des axes à l'affichage (spectre complet) 
freqmin = freq(1);
freqmax = freq(N);
Ymin = min(abs(Y));
Ymax = 1.2*max(abs(Y));

% limites des axes à l'affichage (zoom autour de f = 0 hz ) 
freqmin_z1 = -100;
freqmax_z1 = 100;

%-----------------------------------------------------------------------------------
figure;
% Q2. EN VOUS INSPIRANT DU SCRIPT TP3_script2.m, 
%     (a) AFFICHER LE SPECTRE CENTRE COMPLET SUR UN PREMIER CADRAN,
%     (b) AFFICHER UN ZOOM DU SPECTRE SUR UN SECOND CADRAN 
%         SUR L'AXE DES ABCISSES, ON METTRA LA FREQUENCE 
%      Remarque : freq est la variable fréquence, centrée autour de 0 hz 
 
%...................
%...................

%----------------------------------------------------------------------------








