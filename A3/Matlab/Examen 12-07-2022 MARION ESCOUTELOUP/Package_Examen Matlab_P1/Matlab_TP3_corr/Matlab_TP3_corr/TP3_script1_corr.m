%  Auteur : Mohamed TRIA
%  Objectif  : Generation d'un signal sinusoidal, shannon, Fourier
%  Date : 20/01/2020 
%  Version : 2
clear all;
close all;

%=================================================================================%
%=====  Creation d'un signal sinusoidal y(t) de frequence fo = 50 Hz :       =====%
%=================================================================================%

%---- Construction des variables temps et frequence
fo = 50; % frequence du signal 
Fe = 1e3;  % Shannon Nyquist : "Le signal est bien échantillonné si  Fe/2 > fmax du signal

DT = 1; % duree du signal = 1s
dt = 1/Fe; % periode d'echantillonnage
N = floor(DT/dt)+1;

t = 0:dt:(N-1)*dt; % vecteur variable temps

f = ((0:N-1)/N)*Fe; % f = [0 Fe]
freq = [f(ceil(N/2)+1:N)-Fe f(1:ceil(N/2))]; %f = [-Fe/2 Fe/2]

%---- Construction du signal y(t) 
y = sin(2*pi*fo*t);

%----  Construction des limites des axes à l'affichage

% limites des axes à l'affichage (signal complet) 
tmin = t(1);
tmax = t(N);
ymin = -1.5;
ymax = 1.5;

% limites des axes à l'affichage (zoom sur partie du signal ) 
tmin_z = 0;
tmax_z = 0.1;


figure;

% cadran n°1 de la figure : affichage du signal complet
subplot(2,1,1); 
plot(t,y);
axis([tmin tmax ymin ymax]);
title('Signal complet [frequence = 50 hz]');
xlabel('Temps (s)');

% cadran n°2 de la figure : zoom sur le signal
subplot(2,1,2);
plot(t,y);
axis([tmin_z tmax_z ymin ymax]);
title('Portion du signal (zoom) [frequence = 50 hz]');
xlabel('Temps (s)');


save signal y Fe t N f freq fo
