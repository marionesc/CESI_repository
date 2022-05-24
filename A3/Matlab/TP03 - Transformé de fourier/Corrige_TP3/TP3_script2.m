%  Auteur : Mohamed TRIA
%  Objectif  : Algorithme rapide de Fourier bis
%  Date : 20/01/2020 
%  Version : 2
%  SCRIPT EXERCICE 2
clear all;
close all;

%---- Chargement du signal et des parametres
load signal

%============================================================%
%=====  Creation du spectre du signal  : Y(f)           =====%
%============================================================%


%--------------------------------------------------------------------------
% Q1. CONSTRUIRE LA TRANSFORMEE DE FOURIER DU SIGNAL y(t)
Y = fft(y);

%--------------------------------------------------------------------------
%----  Construction des limites des axes à l'affichage
f = ((0:N-1)/N)*Fe; % f = [0 Fe]

% limites des axes à l'affichage (spectre complet) 
fmin = f(1);
fmax = f(N);
Ymin = min(abs(Y));
Ymax = 1.2*max(abs(Y));

% limites des axes à l'affichage (zoom autour de f = 50 hz ) 
fmin_z1 = 40;
fmax_z1 = 100;

% limites des axes à l'affichage (zoom autour de f = 950 hz ) 
fmin_z2 = 900;
fmax_z2 = 960;


figure;

%--------------------------------------------------------------------------
% cadran n°1 : spectre complet sur f = [0,Fe]
subplot(3,1,1);

%Q2a. AFFICHER LE SPECTRE DU SIGNAL (MODULE DE LA TRANSFORMEE DE FOURIER)
%    AVEC LA VARIABLE f EN ABCISSE 
%    TITRE DANS LE CADRAN n°1 : SPECTRE COMPLET
%    LABEL SUR L'AXE X : FREQUENCES (Hz)


%...........................
%...........................
%...........................
plot(f, abs(Y))
axis([fmin fmax Ymin Ymax]);
title(' Spectre complet ');
ylabel(' Amplitude ');
xlabel(' Fréquence [Hz]');




%---------------------------------------------------------------------------
% cadran n°2 : zoom n°1 sur f = [0hz,100hz]
subplot(3,1,2);
%Q2b. AFFICHER LE SPECTRE DU SIGNAL (MODULE DE LA TRANSFORMEE DE FOURIER)
%    AVEC LA VARIABLE f EN ABCISSE 
%    TITRE DANS LE CADRAN n°2 : SPECTRE AUTOUR DE 50HZ
%    LABEL SUR L'AXE X : FREQUENCES (Hz)

%...........................
%...........................
%...........................
plot(f, abs(Y))
axis([fmin_z1 fmax_z1 Ymin Ymax]);
title(' Spectre complet ');
ylabel(' Amplitude ');
xlabel(' Fréquence [Hz]');
%---------------------------------------------------------------------------

%---------------------------------------------------------------------------
% cadran n°3 : zoom n°2 sur f = [4900hz,5000hz]
subplot(3,1,3);
%Q2c. AFFICHER LE SPECTRE DU SIGNAL (MODULE DE LA TRANSFORMEE DE FOURIER)
%    AVEC LA VARIABLE f EN ABCISSE 
%    TITRE DANS LE CADRAN n°3: SPECTRE AUTOUR DE 4950HZ
%    LABEL SUR L'AXE X : FREQUENCES (Hz)

%...........................
%...........................
%...........................
plot(f, abs(Y))
axis([fmin_z2 fmax_z2 Ymin Ymax]);
title(' Spectre complet ');
ylabel(' Amplitude ');
xlabel(' Fréquence [Hz]');
