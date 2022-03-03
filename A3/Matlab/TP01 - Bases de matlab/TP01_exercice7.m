## Copyright (C) 2022 mario
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {@var{result} =} TP01_exercice7 (@var{rayon}})
##
## @seealso{}
## @end deftypefn

## Author: mario <mario@LAPTOP-NL5I3IEJ>
## Created: 2022-02-11

clear; 
clc; 

display("calcul de la surface d'un disque");

function surface = surfaceDisque(rayon)
  surface = pi * rayon^2;
endfunction

function reste = resteDivEuc(divise, diviseur)
  division = floor(divise / diviseur);
  reste = divise - diviseur * division; 
endfunction

function result = bruitSinus(N, x)
  b = rand(1, N); 
  b0 = b - 0,5; 
  b1 = b0 ./4;
  result = sin(x) + b1;
endfunction