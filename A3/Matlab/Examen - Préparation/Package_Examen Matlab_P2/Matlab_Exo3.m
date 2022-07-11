clear all;
close all;

# Chargement de la data altérée Tx_err (à corriger) et la data vrai Tx

load data1

#### Correction de l'erreur de données
[Rang_Erreur, Valeur_Correcte] = correcteur_erreur_corr(Tx_err);

fprintf("L'erreur se situe sur la donnee de rang %d et la valeur correcte est %d \n", Rang_Erreur, Valeur_Correcte);


### Affichage de la vrai data et celle qui a été altérée
Tx
Tx_err

