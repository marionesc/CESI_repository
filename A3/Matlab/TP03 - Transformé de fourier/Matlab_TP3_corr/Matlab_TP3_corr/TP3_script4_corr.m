%  Auteur : Mohamed TRIA
%  Objectif  : Algorithme rapide de Fourier
%  Date : 20/01/2020 
%  Version : 2
clear all;
close all;

%---- Chargement du signal et des parametres
load signal


%====================================================================%
%=====  Spectre centré d'une exponentielle complexe             =====%
%====================================================================%

% Q1. Construire le signal temporel d'une exponentielle complexe a la frequence fo : ye

ye = exp(j*2*pi*fo*t);


% Q2. Afficher la partie réelle de ce signal 
tmin = min(t);
tmax  = max(t);
ymin = 1.2*min(real(ye));
ymax = 1.2*max(real(ye));

figure;

plot(t, real(ye));
axis([tmin tmax ymin ymax]);
title('Partie reelle de l''exponentielle complexe');
xlabel('Temps (s)');


% Q2. Construire le spectre centré du signal 

Ye = fftshift(fft(ye));

% Q3. Afficher en mettant la variable freq en abcisse

freqmin = min(freq);
freqmax  = max(freq);
Yemin = min(abs(Ye));
Yemax = 1.2*max(abs(Ye));


figure;

plot(freq, abs(Ye));
axis([freqmin freqmax Yemin Yemax]);
title('Spectre d'' exponentielle complexe');
xlabel('Frequences (Hz)');

return;
% Q4. Conclure par rapport a la théorie



