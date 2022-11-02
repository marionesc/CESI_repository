% Auteur : Mohamed TRIA
% Date : 26/03/2020
% Objectif : pratiquer le suréchantillonnage d'un signal par méthode d'interpolation
clear all;
close all;
pkg load signal
tmin =0; % temps initial
tmax = 1; % temps final
Fe =100; % fréquence d'échantillonnage
fo = 1; % fréquence du signal

t = tmin:1/Fe:tmax; % variable temps









y = sin(2*pi*fo*t); % notre signal

factsample =5; % on veut interpoler des points entre 2 points du signal d'origine
y2 = interp(y,factsample); % création du signal suréchantillonné
Fe2 = factsample*Fe; % nouvelle fréquence du signal

t2=tmin:1/Fe2:tmax; % nouvel variable temps 
y2=y2(1:length(t2));

% affichage des 2 signaux (origine et suréchantillonné)
figure;
plot(t,y,'bx');
hold on;
plot(t2,y2,'ro');

