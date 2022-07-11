##### Exercice n°2  : traitement du signal et filtrage numérique #######
### L'objectif de cette exercice est d'analyser le spectre du signal
### et de filtrer une partie du bruit par filtrage numérique

clear all;
close all;

fo = 5; % fréquence du signal
A = 1; % amplitude du signal
Fe = 500; % fréquence d'échantillonnage

tmin = 0; % temps minimal
tmax = 1; % temsp maximum


## Q1. Constituer le vecteur temps nommé t à partir de tmin, tmax et Fe
...........................

## Q2 . Récupérer la taille du vecteur temps, nommé N
..........................


## on donne un signal sinusoidal 
signal  =  A*sin(2*pi*fo*t);

## Q3. Afficher le signal en fonction du temps
............................

###########################################
##### Partie 1 : Analyse spectrale ########
###########################################


###  Q4. Construire le vecteur frequence nommé freq 
## On donne 
fmin = -Fe/2;
fmax = Fe/2;
df = 1/(tmax-tmin);
...................................

### s'assurer que la variable fréquence a la même longueur que le signal 
freq = freq (1:length(signal));

## Q5. Construire le spectre du signal en bande de base, c'est à dire 
## sur freq = [-Fe/2, Fe/2]
....................................


## On récupère dans freqsignal_idx les indices des pics de fréquence du spectre
[max,freqsignal_idx] = findpeaks(Spectre);

## Afficher le spectre en fonction de la fréquence
...............
...............

## On affiche sur le titre de la figure les 2 fréquences du signal
## Compléter les .....  
title(['Frequences du signal (Hz) = ', num2str(.....),'Hz  et ',num2str(.......),'Hz']);

######################################
###### Partie 2 : Filtrage     #######
######################################

#### Q6. Demander à l'utilisateur : 
## 1. de donner le rapport signal à bruit, nommé SNR (L'utilisateur donnera une valeur de 5 ou 10)
## 2. de donner l'ordre du filtre, nommé n (L'utilisateur donnera une valeur 4,5 ou 6) 

..............................................
..............................................

### Exprimer sigma (écart-type) en fonction de A et de SNR 
.............................

### Q7. Construire un vecteur bruit de même dimension que le signal et fonction de sigma
###     et contruire un signal bruité
......................
......................


#### Q8. Demander à l'utilisateur : 
#### l'ordre du filtre, nommé n

#### Q9. construire les paramètres A et B du filtre moyenneur
A = ............
B = ............
   

#### Q10. Construire la réponse fréquentielle du filtre : compléter les ....
      
[H,f] = .....

% f donnée entre [0,pi] => normalisation de f entre [0,Fs/2]
f = f*Fe/(2*pi); 

#### Q11. Afficher la réponse H du filtre en fonction de la  fréquence f
............


#### Q12. Appliquer le filtre au signal bruité pour construire le signal filtré, nommé sortie_filtre

......... 

N_sf = length(sortie_filtre); % dimension du signal en sortie du filtre
t_sf = t(1:N_sf); % constitution du vecteur temps  associé à la sortie du filtre


#### Q13. Superposer le signal bruité et le signal en sortie de filtre sur une même figure
..................
..................
..................
