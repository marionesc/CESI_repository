%  Auteur : Mohamed TRIA
%  Objectif  : Algorithme rapide de Fourier (FFT)
%  Date : 20/01/2020 
%  Version : 1
clear all;
close all;

%---- Chargement du signal et des parametres
load signal

%============================================================%
%=====  Creation du spectre du signal  : Y(f)           =====%
%============================================================%



%---- Construction de la transformee de Fourier Y(f) = Fourier[y(t)]

% Q2. Construire la Transformée de Fourier du signal y
% Y = ....

Y = fft(y);



%----  Construction des limites des axes à l'affichage

% limites des axes à l'affichage (spectre complet) 
fmin = f(1);
fmax = f(N);
Ymin = min(abs(Y));
Ymax = 1.5*max(abs(Y));

% limites des axes à l'affichage (zoom autour de f = 50 hz ) 
fmin_z1 = 40;
fmax_z1 = 100;

% limites des axes à l'affichage (zoom autour de f = 950 hz ) 
fmin_z2 = 900;
fmax_z2 = 960;


figure;

% cadran n°1 : spectre complet sur f = [0,Fe]
subplot(3,1,1);

%Q3a. Afficher le spectre du signal (module de la transformée de Fourier)
% avec la fréquence en abcisse
plot(f,abs(Y));

axis([fmin fmax Ymin Ymax]);
title('Spectre complet');
xlabel('Frequences (Hz)');


% cadran n°2 : zoom n°1 sur f = [0hz,100hz]
subplot(3,1,2);
% Q3b. 
plot(f,abs(Y));
axis([fmin_z1 fmax_z1 Ymin Ymax]);
title('Spectre autour de 50 Hz');
xlabel('Frequences (Hz)');

% cadran n°3 : zoom n°2 sur f = [4900hz,5000hz]
subplot(3,1,3);
% Q3c. 
plot(f,abs(Y));
axis([fmin_z2 fmax_z2 Ymin Ymax]);
title('Spectre autour de 4950 Hz');
xlabel('Frequences (Hz)');

% Q4. Quel phénomène est mis en évidence dans l'affichage du spectre

return,


%====================================================================%
%=====  Centrage du spectre  Y(f) autour de freq = 0hz          =====%
%====================================================================%


%--- Centrage du spectre autour de freq = 0 hz 
% ==> FFTSHIFT = Le cadran droit d'origine devient cadran gauche  (freq <0) et cadran gauche d'origine devient cadran droit (freq >0)

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



%---- Construction du signal y(t) complexe 
y2 = exp(j*2*pi*fo*t);
Y2 = fftshift(fft(y2));
figure;
plot(freq, abs(Y2));





