clear all;
close all;

# Chargement de la data alt�r�e Tx_err (� corriger) et la data vrai Tx

load data1

#### Correction de l'erreur de donn�es
[Rang_Erreur, Valeur_Correcte] = correcteur_erreur_corr(Tx_err);

fprintf("L'erreur se situe sur la donnee de rang %d et la valeur correcte est %d \n", Rang_Erreur, Valeur_Correcte);


### Affichage de la vrai data et celle qui a �t� alt�r�e
Tx
Tx_err

