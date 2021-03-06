function [sig,t] = Gen_Signal(varargin);
  
%===================================================================%
% FONCTION GENERANT UN SIGNAL COMPLEXE A LA FREQUENCE fo   
% [sig,t] = gen_signal(N,fo,tmax,Fe)
%
% ENTREES [valeurs par d?faut]
% N  : Nombre d'echantillons [512]
% fo : frequence du signal (Hz) [50]
% tmax : temps final du signal (s) [1]
% Fe: frequence d'echantillonnage (Hz) [1000] 
%
% SORTIE
% sig : signal complexe exp(j*2*pi*fo*t)
% t   : temps
% 
% EXEMPLES 
%
% [sig,t] = Gen_signal(); parametres par d?faut N = 512, fo = 50Hz
%                         tmax = 1s et Fe = 1khz
%  N = 2048;
% [sig,t] = Gen_Signal(N)
%
% N = 2048; fo = 75;
% [sig,t] = Gen_Signal(N,fo);
% ....
%
% N = 1024; fo = 75; tmax = 2.5; Fe = 2e3
% [sig,t] = Gen_signal(N,fo,tmax,Fe)
%
%
%
%===================================================================%



if (nargin ==0)
  ???????????
  ???????????
  ???????????
endif

if nargin ==1
 ???????????
  ???????????
  ???????????
endif

if nargin ==2
 ???????????
  ???????????
  ???????????
endif  
  
if nargin ==3
???????????
  ???????????
  ???????????
endif 
 
if nargin == 4 
???????????
  ???????????
  ???????????
endif

 
t = 0:????:tmax;
sig = ??????????

