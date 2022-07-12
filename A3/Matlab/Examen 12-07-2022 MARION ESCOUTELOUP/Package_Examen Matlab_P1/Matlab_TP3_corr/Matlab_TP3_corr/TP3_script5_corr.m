%  Auteur : Mohamed TRIA
%  Objectif  : Notion de fenetrage
%  Date : 20/01/2020 
%  Version : 1
clear all;
close all;

load signal 

%=================================================================================%
%=====  Creation d'un signal e(t) = rect. sin(2pifot)                        =====%
%=================================================================================%

%------------------------------------------------------------------------------------
% Q1. EN UTILISANT LA COMMANDE find, METTRE A 0 TOUS LES ECHANTILLONS SIGNAL > 0.1s
T = 0.1;
I = find (t> T);
y(I) = 0;
%yr = y;
%yr(I) = 0; 
%------------------------------------------------------------------------------------

%------------------------------------------------------------------------------------
% Q2. CONSTRUIRE LA FFT CENTREE Y(f) de y(t)
Y = fftshift(fft(y));


%------------------------------------------------------------------------------------


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
subplot(2,1,1); 
plot(t,y);
axis([tmin tmax ymin ymax]);
title('Signal emis');
xlabel('Temps (s)');


%-----------------------------------------------------------------------

%-----------------------------------------------------------------------
% Q3b. AFFICHER LE SPECTRE DU SIGNAL SUR UN SECOND CADRAN 
%     EN UTILISANT LES LIMITES DES AXES freqmin, freqmax Ymin, Ymax
subplot(2,1,2);
plot(freq,abs(Y));
axis([freqmin freqmax Ymin Ymax]);
title('Spectre du signal emis');
xlabel('Frequences (Hz)');




% Q4. Superposer les fenêtres de hamming, blackman, hanning sur le signal temporel
I = find(t<=T);
Ne = max(I);
ham = hamming(Ne);
ham = [ham;zeros(N-Ne,1)];
ham = ham.';
han = hanning(Ne);
han = [han;zeros(N-Ne,1)];
han = han.';
blk = blackman(Ne);
blk = [blk;zeros(N-Ne,1)];
blk = blk.';

figure;
plot(t,y), hold on
plot(t,ham,'c');
plot(t,han,'r');
plot(t,blk,'g');
axis([tmin tmax ymin ymax]);


yham = y.*ham;
yhan = y.*han;
yblk = y.*blk;

Yham = fftshift(fft(yham));
Yhan = fftshift(fft(yhan));
Yblk = fftshift(fft(yblk));


figure;
plot(freq,abs(Y)),hold on
plot(freq, abs(Yham),'c');
plot(freq, abs(Yhan),'r');
plot(freq, abs(Yblk),'g');
axis([freqmin freqmax Ymin Ymax]);
title('Spectre du signal emis');
xlabel('Frequences (Hz)');
legend('spectre initial','avec hamming','avec hanning','avec blackman');









