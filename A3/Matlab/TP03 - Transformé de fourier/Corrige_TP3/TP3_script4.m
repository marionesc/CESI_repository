%  Auteur : Mohamed TRIA
%  Objectif  : Algorithme rapide de Fourier
%  Date : 20/01/2020 
%  Version : 2
clear all;
%close all;

%---- Chargement du signal et des parametres
load signal


%====================================================================%
%=====  Spectre centré d'une exponentielle complexe             =====%
%====================================================================%

%------------------------------------------------------------------------------------
% Q1. CONSTRUIRE LE SIGNAL TEMPOREL D'UNE EXPONENTIELLE COMPLEXE A LA FREQUENCE fo
%     CE SIGNAL SERA NOTE ye 

ye = exp(j*2*pi*fo*t);
ye2 = exp(j*2*pi*(-fo)*t);  % ye = exp(-j*2*pi*fo*t);

%------------------------------------------------------------------------------------

% Q2. AFFICHER LA PARTIR REELLE DE CE SIGNAL
%     L'AXE DES ABCISSES SERA LE TEMPS t 
%     LES LIMITES DE L'AXE DES ORDONNEES SERA 20% AU DESSUS DES LIMITES DU SIGNAL
%     PUR BIEN VISUALISER LE SIGNAL  

ye_reel = real(ye);%cos(2*pi*fo*t);
%ye_reel = sin(2*pi*fo*t);

tmin = t(1);
tmax = t(N);
yemin = 1.2*min(ye_reel);
yemax = 1.2*max(ye_reel);;
figure(1);
plot(t,ye_reel);
title("PARTIE REELLE DU SIGNAL");
xlabel("Temps (s)");
ylabel("Partie reelle su signal exp(j 2 pi fo t)");
axis([tmin tmax yemin yemax]);

%-------------------------------------------------------------------------------------


%-------------------------------------------------------------------------------------
% Q3. CONSTRUIRE ET AFFICHER LE SPECTRE CENTRE (VARIABLE freq EN ABSCISSE) 
%     LES LIMITES DE L'AXE DES ORDONNEES SERA 20% AU DESSUS DES LIMITES DU SPECTRE
%     PUR BIEN VISUALISER LE SPECTRE

fmin_z1 = -100;
fmax_z1 = 100;
Xe = fftshift(fft(ye));
Xe2 = fftshift(fft(ye2));
Ye = fftshift(fft(ye_reel));

Xemin = min(abs(Xe));
Xemax = 1.2*max(abs(Xe));
figure(2);
subplot(3,1,1)
plot(freq,abs(Xe))
axis([fmin_z1 fmax_z1 Xemin Xemax])
title(" SPECTRE CENTRE du signal xe(t)=exp(j 2 pi fo t)")
xlabel("Frequence (Hz)")


subplot(3,1,2)
plot(freq,abs(Xe2))
axis([fmin_z1 fmax_z1 Xemin Xemax])
title(" SPECTRE CENTRE du signal xe(t)=exp(j 2 pi (-fo) t)")
xlabel("Frequence (Hz)")

subplot(3,1,3)
plot(freq,abs(Ye))
axis([fmin_z1 fmax_z1 Xemin Xemax])
title(" SPECTRE CENTRE du signal xe(t)=cos(2 pi fot)")
xlabel("Frequence (Hz)")

%-------------------------------------------------------------------------------------



