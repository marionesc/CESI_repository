%  Auteur : Mohamed TRIA
%  Objectif  : Application radar dans la localisation de cibles
%  Date : 20/01/2020 
%  Version : 2
clear all;
close all;

%=================================================================================%
%=====  Creation d'un signal e(t) = rect. sin(2pifot)   et réception r(t)    =====%
%=================================================================================%

load signal2

% limites des axes à l'affichage (temporel) 
tmin = t(1);
tmax = t(N);
ymin = -1.5;
ymax = 1.5;

figure
plot(t,e);
axis([tmin tmax ymin ymax]);
title('Signal emis');

figure;
plot(t,r);
axis([tmin tmax ymin ymax]);
title('Signal reflechi');

corr = ifft(fft(r).*conj(fft(e)));

c = 340;
figure;
plot(c*t/2,abs(corr));
xlabel('Distance (m)');
title('Calcul de distance par intercorrelation');








