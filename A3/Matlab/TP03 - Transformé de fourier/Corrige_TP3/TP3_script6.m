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
c = 340; % vitesse de l'onde acoustique en m/s

% limites des axes à l'affichage (temporel) 
tmin = t(1);
tmax = t(N);
ymin = -1.5;
ymax = 1.5;

figure
plot(t,e);
axis([tmin tmax ymin ymax]);
xlabel('Temps (s)');
title('Signal emis');


figure;
plot(t,r);
axis([tmin tmax ymin ymax]);
xlabel('Temps (s)');
title('Signal reflechi');

%----------------------------------------------------------------------------------------------
% Q1. REALISER LA FONCTION D'INTERCORRELATION ENTRE LE SIGNAL REFLECHI ET LE SIGNAL EMIS
%----------------------------------------------------------------------------------------------

%.........................


%----------------------------------------------------------------------------------------------
% Q2. AFFICHER LE MODULE DE LA FONCTION D'INTERCORRELATION EN FONCTION DE LA DISTANCE (en m)
%----------------------------------------------------------------------------------------------

%.........................
%.........................
%.........................









