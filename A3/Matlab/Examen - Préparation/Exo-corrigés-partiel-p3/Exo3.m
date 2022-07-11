% === Analyse spectrale ===%

load data
% contient le signal y, la variable temps t et la variable fréquence f


% Q1. Afficher le signal en fonction du temps
figure (1);
plot(t,y);    %A rajouter
xlabel('temps'); %A rajouter
title('fonction y(t)'); %A rajouter


% Q2. Construire le spectre du signal et l'afficher en fonction de la fréquence 
Y = fft(y);   %A rajouter

figure(2);
plot(f,Y);    %A rajouter
xlabel('fréquence'); %A rajouter
title('fonction y(f)'); %A rajouter

% Q3. Trouver les fréquences  présentes dans le signal 
%     On supposera que si l'amplitude du signal est supérieur > 70% du maximum
%      c'est qu'on a détecté un pic et donc une fréquence du signal 

Seuil = 0.7*max(Y);

% Indication / aide : on pourra utiliser la commande find() pour trouver les indices de fréquences
%  présentes dans le signal 
% et faire une boucle for avec n, le nombre d'indices trouvés comme nombre d'itérations
% dans la boucle 

% A rajouter
test=find(Y>Seuil) % on récupère dans test les 2 valeurs 

for n = 1: length(test)
  g=test(n)
  fsignal(n) = f(g)
 endfor


% Si 2 pics sont trouvés : on appelera fsignal(1) et fsignal(2) ces fréquences
% Si 3 pics sont trouvés; on appelera fsignal(1); fsignal(2) et fsignal(3) ces fréquences
% etc .... 










