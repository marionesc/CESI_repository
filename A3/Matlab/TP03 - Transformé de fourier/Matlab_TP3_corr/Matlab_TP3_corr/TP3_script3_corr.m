%  Auteur : Mohamed TRIA
%  Objectif  : Algorithme rapide de Fourier et FFTSHIFT
%  Date : 20/01/2020 
%  Version : 2
clear all;
%close all;

%---- Chargement du signal et des parametres
load signal


%====================================================================%
%=====  Centrage du spectre  Y(f) autour de freq = 0hz          =====%
%====================================================================%

%--- Centrage du spectre autour de freq = 0 hz  = [-Fe/2 Fe/2]

% ==> fonction fftshift = Le cadran [Fe/2 Fe] est déporté à gauche et devient [-Fe/2 0]
%                Le cadran [0 Fe/2] est déporté à droite et reste à [0,Fe/2] 

% Q1. Realiser le centrage du spectre en utilisant fft et fftshift

Y = fft(y);
Y = fftshift(Y);



%----  Construction des limites des axes à l'affichage

% limites des axes à l'affichage (spectre complet) 
freqmin = freq(1);
freqmax = freq(N);
Ymin = min(min(abs(Y)));
Ymax = 1.2*max(max(abs(Y)));

% limites des axes à l'affichage (zoom autour de f = 0 hz ) 
freqmin_z1 = -100;
freqmax_z1 = 100;


figure;

% cadran n°1 : spectre complet
subplot(2,1,1);
plot(freq,abs(Y));
axis([freqmin freqmax Ymin Ymax]);
title('Spectre complet');
xlabel('Frequences (Hz)');
%cadran n°2 : 
subplot(2,1,2);
plot(freq,abs(Y));
axis([freqmin_z1 freqmax_z1 Ymin Ymax]);
title('Spectre autour de 0 Hz');
xlabel('Frequences (Hz)');

return;

% Q2. En faisant le lien avec la théorie, expliquer pourquoi nous avons 2 raies, une en -50hZ et une en 50hz.


%---- Construction du signal y(t) complexe 
%y2 = exp(j*2*pi*fo*t);
%Y2 = fftshift(fft(y2));
%figure;
%plot(freq, abs(Y2));





