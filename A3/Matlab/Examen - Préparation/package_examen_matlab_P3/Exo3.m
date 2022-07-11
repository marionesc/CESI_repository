% === Analyse spectrale ===%

load data
% contient le signal y, la variable temps t et la variable fr�quence f


% Q1. Afficher le signal en fonction du temps
figure (1);
................


% Q2. Construire le spectre du signal et l'afficher en fonction de la fr�quence 
Y = .................

figure(2);
.....................


% Q3. Trouver les fr�quences  pr�sentes dans le signal 
%     On supposera que si l'amplitude du signal est sup�rieur > 70% du maximum
%      c'est qu'on a d�tect� un pic et donc une fr�quence du signal 

Seuil = 0.7*max(Y);

% Indication / aide : on pourra utiliser la commande find() pour trouver les indices de fr�quences
%  pr�sentes dans le signal 
% et faire une boucle for avec n, le nombre d'indices trouv�s comme nombre d'it�rations
% dans la boucle 

.................
................
................
.................

% Si 2 pics sont trouv�s : on appelera fsignal(1) et fsignal(2) ces fr�quences
% Si 3 pics sont trouv�s; on appelera fsignal(1); fsignal(2) et fsignal(3) ces fr�quences
% etc .... 










