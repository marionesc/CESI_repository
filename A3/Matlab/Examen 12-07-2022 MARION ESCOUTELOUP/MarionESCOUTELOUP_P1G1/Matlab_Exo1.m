##
## DOCUMENT REMPLI PAR MARION ESCOUTELOUP
##    GitHub : maresc
##
##  12/07/2022
##
##  Cours CESI - FIPA 26 S3E
##  Matlab & Octave

########################################################
####### Exercice n°1 : Résolution de systèmes ##########
########################################################

clear all;
close all;


### Partie A ######


% Soit la formulation matricielle Y = AX

% Q1_A.  Construire les matrices A et Y

A = [1,0, 2 ; 0,-1,1 ; 1,-2,0];
Y = [1 ; 2 ; 1];


% Q2_A. En déduire la matrice X des solutions du système d'équation
X = inv(A)*Y;


### partie B  #####

% le couple de solutions (x,y) satisfaisant au système d'équations vérifient
% x+my = -3
% mx+4y = 6

% Objectif : Trouver une solution  (x,y) du système d'équation
% Pour cela, nous allons construire les droites :
% y1 = (-3-x)/m
% y2 =  (6-mx)/4


% Soit le vecteur x = -10:0.1:10

xmin = - 10;
xmax = 10;
dx = 0.1;

x = xmin:dx:xmax;

% Q3_B. Construire un vecteur contenant les valeurs m = -2 1 2 et 3
M = [-2 1 2 3];

figure;

% Identification des valeurs de m qui conviennent
% On se propose de calculer les droites y1 et y2 pour les différentes valeurs de m

% Q4_B. Compléter les lignes en pointillés dans la boucle for
%       pour afficher sur 4 cadrans m =-2, m=1, m=2 et m=3
%       les droites y1 et y2

for i = 1:length(M)

    m = M(i);
    y1(:,i) = (-3 - x) / m;

    y2(:,i) = (6 - m*x)/4;

    subplot(2,2,i)
    plot(x, y1)
    hold on
    plot(x, y2);

    title(['Cas des droites pour m =',num2str(m)]);
    xlabel('x');

end

% on s'interesse maintenant à m = 1;
% Q5_B Compléter les lignes en pointillés ci-dessous
i = 2;
m = M(2);
% On recherche l'indice pour lequel les droites y1 et y2 se coupent (y1 = y2)
I = find(abs(y1(:,i)-y2(:,i)) < 1e-2);

% En déduire xo_1 tel que y1(xo_1) = y2(xo_1)
xo_1 = (12 + 6*m)/(m^2 - 4);

% on donne yo_1
yo_1 = (-3-xo_1)/m;

% on affiche le résultat
printf("Par la methode graphique, une des solutions du systeme est x = %f y = %f\n",xo_1,yo_1);



% En considerant le système d'équation avec m = 1
% Resoudre le système par calcul matriciel (même méthodologie que la partie A)
% Q5_B Compléter les lignés en pointillés ci-dessous
% On vérifiera donc qu'on retrouve le même résultat qu'à la question précédente
m = 1;
A = [1, m ; m ,4]
Y = [-3 ;6];
X = inv(A)*Y;

xo_2 = X(1);
yo_2 = X(2);

printf("Par la methode matricielle, une des solutions du systeme est %f %f\n",xo_2,yo_2);

