% Auteur : Mohamed TRIA
% Date : 23/03/2020
% Realisation d'un filtre moyenneur d'ordre 1 ou 3 ou dérivateur
clear all;
close all;

% Filtre moyenneur d'ordre 1 / ordre 3
A = [1];
B = [1/2 1/2]; %  Ordre 3 => B  = [1/4 1/4 1/4 1/4] 
N = 512;
Fe = 1e3;
[H,f] = freqz(B,A,N,Fe);
figure;
plot(f,20*log10(abs(H)));
xlabel('Frequences (Hz)');
title('Reponse frequentielle du filtre');

% commande find --> fc
HdB = 20*log10(abs(H));
HdBmax = max(HdB);
I = find(HdB <= HdBmax-3);
Ic = min(I);
fc = f(Ic);


% application du filtre en temporel

t = 0:1/Fe:(N-1)*(1/Fe);
fo = 10;
signal = sin(2*pi*t*fo);
sigma = 0.1;
bruit = sigma*randn(1,N) ; % bruit suivant la loi normale
signalb = signal + bruit ; % signal bruité
y = filter(B,A,signalb); % application du filtre (à partir de ses coefficients A et B)  sur le                
                                            % signal bruité
figure;
subplot(2,1,1); % subdivision de la figure en 2 graphes
plot(t,signalb); % visualization du signal bruité
title('signal en entree du filtre');
xlabel('Temps (s)');
subplot(2,1,2);
plot(t,y);  % visualization du signal après filtrage moyenneur 
title('signal en sortie du filtre');
xlabel('Temps (s)');
 

 % Filtre derivateur
 A = [1];
B = [1/2 -1/2]; 
y = filter(B,A,signal); % application du filtre (à partir de ses coefficients A et B)  sur le                
 figure;
subplot(2,1,1); % subdivision de la figure en 2 graphes
plot(t,signal); % visualization du signal bruité
title('signal en entree du filtre');
xlabel('Temps (s)');
subplot(2,1,2);
plot(t,y./max(y));  % visualization du signal après filtrage moyenneur 
title('signal en sortie du filtre');
xlabel('Temps (s)');                                           % signal bruité