%  Auteur : Mohamed TRIA
%  Objectif  : Application du fenetrage en radar
%  Date : 20/01/2020 
%  Version : 2
clear all;
close all;

% chargement du signal et de ses parametres
load signal3
% vitesse de l'onde en m/s
c = 340; 


%----  Construction des limites des axes à l'affichage

% limites des axes à l'affichage (temporel) 
tmin = t(1);
tmax = t(N);
ymin = -1.5;
ymax = 1.5;


figure;

% cadran n°1 de la figure : affichage du signal emis
subplot(2,1,1); 
plot(t,e);
axis([tmin tmax ymin ymax]);
title('Signal emis');
xlabel('Temps (s)');

% cadran n°2 de la figure : affichage du signal reflechi
subplot(2,1,2);
plot(t,real(r));
axis([tmin tmax ymin ymax]);
title('Signal reflechi');
xlabel('Temps (s)');


%------------------------------------------------------------
% Q1. (a) REALISER LA FONCTION D'INTERCORRELATION 
%     (b) AFFICHER SON MODULE EN FONCTION DE LA DISTANCE
%     (c) IDENTIFIER LA DISTANCE DE LA CIBLE EN METRES

%.............................
%.............................
%.............................
%.............................
%.............................


%-------------------------------------------------------------
% ON CHERCHE MAINTENANT A REDUIRE LES LOBES SECONDAIRES OBSERVES 
% DANS LA FONCTION D'INTERCORRELATION 
% NOUS CONSTRUISONS POUR CELA LA FENETRE DE HAMMING DANS LE DOMAINE FREQUENTIEL

I = find(freq>=0 & freq <=100);
Nm = min(I);
NM = max(I);
ham = hanning(NM-Nm);

ham = [zeros(Nm,1); ham; zeros(N-NM,1)];
ham = ham.';

figure
plot(freq,ham);

% Q1. CONSTRUIRE LE SPECTRE CENTRE DE LA FONCTION D'INTERCORRELATION

%...............................


% Q2. APPLIQUER LA FENETRE DE HAMMING AU SPECTRE CI DESSUS

%...............................

% Q3. REVENIR EN TEMPOREL AVEC IFFT 

%...............................

% Q4. AFFICHER LE MODULE DE LA NOUVELLE FONCTION D'INTERCORRELATION (APRES FENETRAGE)

%...............................












