% === Analyse spectrale ===%

load data
% contient le signal y, la variable temps t et la variable fréquence f


% Q1. Afficher le signal en fonction du temps
figure (1);
................


% Q2. Construire le spectre du signal et l'afficher en fonction de la fréquence 
Y = .................

figure(2);
.....................


% Q3. Trouver les fréquences  présentes dans le signal 
%     On supposera que si l'amplitude du signal est supérieur > 70% du maximum
%      c'est qu'on a détecté un pic et donc une fréquence du signal 

Seuil = 0.7*max(Y);

% Indication / aide : on pourra utiliser la commande find() pour trouver les indices de fréquences
%  présentes dans le signal 
% et faire une boucle for avec n, le nombre d'indices trouvés comme nombre d'itérations
% dans la boucle 

.................
................
................
.................

% Si 2 pics sont trouvés : on appelera fsignal(1) et fsignal(2) ces fréquences
% Si 3 pics sont trouvés; on appelera fsignal(1); fsignal(2) et fsignal(3) ces fréquences
% etc .... 










