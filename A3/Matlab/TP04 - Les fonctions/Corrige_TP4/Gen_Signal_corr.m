function [sig,t] = Gen_Signal_corr(varargin);
  
%===================================================================%
% FONCTION GENERANT UN SIGNAL COMPLEXE A LA FREQUENCE fo   
% [sig,t] = Gen_Signal_corr(N,fo,tmax,Fe)
%
% ENTREES [valeurs par défaut]
% N  : Nombre d'echantillons [512]
% fo : frequence du signal (Hz) [50]
% tmax : temps final du signal (s) [1]--> NE SERT PAS DANS LE SCRIPT
% Fe: frequence d'echantillonnage (Hz) [1000] 
%
% SORTIE
% sig : signal complexe exp(j*2*pi*fo*t)
% t   : temps
% 
% EXEMPLES 
%
% [sig,t] = Gen_Signal_corr(); parametres par défaut N = 512, fo = 50Hz
%                         tmax = 1s et Fe = 1khz
%
% N = 1024; fo = 75; tmax = 2.5; Fe = 2e3
% [sig,t] = Gen_Signal_corr(N,fo,tmax,Fe)
%
%
%
%===================================================================%



if (nargin ==0)
  N = 512;
  fo = 50;
  tmax = 1;
  Fe = 1000;
endif

if nargin ==1
  N=varargin{1};
  fo = 50;
  tmax = 1;
  Fe = 1e3;
endif

if nargin ==2
  N=varargin{1};
  fo = varargin{2};
  tmax = 1;
  Fe = 1e3;
endif  
  
if nargin ==3
 N=varargin{1};
 fo = varargin{2};
 tmax = varargin{3};
 Fe = 1e3;
endif 
 
if nargin == 4 
 N=varargin{1};
 fo = varargin{2};
 tmax = varargin{3};
 Fe = varargin{4};
endif


dt = 1/Fe; %Te
t = 0:dt:(N-1)*dt;
sig = exp(j*2*pi*fo*t);

