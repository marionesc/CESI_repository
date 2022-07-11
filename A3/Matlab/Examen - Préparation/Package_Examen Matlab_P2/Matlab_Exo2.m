##### Exercice n�2  : traitement du signal et filtrage num�rique #######
### L'objectif de cette exercice est d'analyser le spectre du signal
### et de filtrer une partie du bruit par filtrage num�rique

clear all;
close all;

fo = 5; % fr�quence du signal
A = 1; % amplitude du signal
Fe = 500; % fr�quence d'�chantillonnage

tmin = 0; % temps minimal
tmax = 1; % temsp maximum


## Q1. Constituer le vecteur temps nomm� t � partir de tmin, tmax et Fe
...........................

## Q2 . R�cup�rer la taille du vecteur temps, nomm� N
..........................


## on donne un signal sinusoidal 
signal  =  A*sin(2*pi*fo*t);

## Q3. Afficher le signal en fonction du temps
............................

###########################################
##### Partie 1 : Analyse spectrale ########
###########################################


###  Q4. Construire le vecteur frequence nomm� freq 
## On donne 
fmin = -Fe/2;
fmax = Fe/2;
df = 1/(tmax-tmin);
...................................

### s'assurer que la variable fr�quence a la m�me longueur que le signal 
freq = freq (1:length(signal));

## Q5. Construire le spectre du signal en bande de base, c'est � dire 
## sur freq = [-Fe/2, Fe/2]
....................................


## On r�cup�re dans freqsignal_idx les indices des pics de fr�quence du spectre
[max,freqsignal_idx] = findpeaks(Spectre);

## Afficher le spectre en fonction de la fr�quence
...............
...............

## On affiche sur le titre de la figure les 2 fr�quences du signal
## Compl�ter les .....  
title(['Frequences du signal (Hz) = ', num2str(.....),'Hz  et ',num2str(.......),'Hz']);

######################################
###### Partie 2 : Filtrage     #######
######################################

#### Q6. Demander � l'utilisateur : 
## 1. de donner le rapport signal � bruit, nomm� SNR (L'utilisateur donnera une valeur de 5 ou 10)
## 2. de donner l'ordre du filtre, nomm� n (L'utilisateur donnera une valeur 4,5 ou 6) 

..............................................
..............................................

### Exprimer sigma (�cart-type) en fonction de A et de SNR 
.............................

### Q7. Construire un vecteur bruit de m�me dimension que le signal et fonction de sigma
###     et contruire un signal bruit�
......................
......................


#### Q8. Demander � l'utilisateur : 
#### l'ordre du filtre, nomm� n

#### Q9. construire les param�tres A et B du filtre moyenneur
A = ............
B = ............
   

#### Q10. Construire la r�ponse fr�quentielle du filtre : compl�ter les ....
      
[H,f] = .....

% f donn�e entre [0,pi] => normalisation de f entre [0,Fs/2]
f = f*Fe/(2*pi); 

#### Q11. Afficher la r�ponse H du filtre en fonction de la  fr�quence f
............


#### Q12. Appliquer le filtre au signal bruit� pour construire le signal filtr�, nomm� sortie_filtre

......... 

N_sf = length(sortie_filtre); % dimension du signal en sortie du filtre
t_sf = t(1:N_sf); % constitution du vecteur temps  associ� � la sortie du filtre


#### Q13. Superposer le signal bruit� et le signal en sortie de filtre sur une m�me figure
..................
..................
..................
