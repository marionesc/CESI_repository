% Construction d'un échantillon de bruit centré autour de 0 entre -0.5 et 0.5
b = rand(1)-0.5;
b = b./4; % b devient entre [-0.125, 0.125]
 
 
 % créer un vecteur bruit donc un signal bruit 

x = 0:0.1:10;
y = sin(x);
N = length(y);

bruit = (rand(1,N)-0.5)./4;

signal_bruit  = y + bruit;

figure;
plot(x,signal_bruit);
xlabel('indice echantillon');
title('sinusoide avec bruit');

