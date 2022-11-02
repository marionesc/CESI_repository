## Copyright (C) 2022 MARION ESCOUTELOUP
##
## Created: 2022-04-11
clear all;
close all;

%%%%%%%%%%%%%%%%%%%%
%% INITIALIZATION %%
%%%%%%%%%%%%%%%%%%%%
%% Initialization of global message
CHOICE_EXERCICE_MESSAGE = "Choississez l'exercice a lancer."

%% Initialization of others variables


%%%%%%%%%%%%%%%
%% MAIN CODE %%
%%%%%%%%%%%%%%%
%% Print command interface message for the project's start
exerciceChoice = menu(CHOICE_EXERCICE_MESSAGE, 'exercice 1', 'exercice 2', 'exercice 3');

switch(exerciceChoice)
  % exercice 1
  case 1
    a = str2double(inputdlg({'valeur a:'}, ...
                             ' entrre des valeurs utilisateurs', [1 30]))
    b = str2double(inputdlg({'valeur b:'}, ...
                             ' entree des valeurs utilisateurs', [1 30]))
    res = TP4_ex1(a,b);
    display(res);


  % exercice 2
case 2
    a = str2double(inputdlg({'valeur a:'}, ...
                                 ' entrre des valeurs utilisateurs', [1 30]))
    b = str2double(inputdlg({'valeur b:'}, ...
                             ' entree des valeurs utilisateurs', [1 30]))


    res = TP4_ex2(a,b);
    display(res);

  % exercice 1
  case 3


end
