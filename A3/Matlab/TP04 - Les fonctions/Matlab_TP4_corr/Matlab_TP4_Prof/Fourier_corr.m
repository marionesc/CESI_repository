function [Y,f,varargout] = Fourier_corr(varargin);
  
%============================================================================%
% FONCTION RETOURNANT LA TRANSFORMEE DE FOURIER D'UN SIGNAL SUR [-Fe/2,Fe/2]    
% [Y,f] = Fourier(y,t)
%
% ENTREES 
% y  : signal temporel 
% t  : temps (s)
%
% ENTREE OPTIONNELLE
% Mode : spectre centrée 'c' ou non 'nc' ['c']
% 
% SORTIES
% Y   :  Transformée de Fourier du signal y(t) 
% f   :  Fréquence (Hz)  
% 
% SORTIES OPTIONNELLES 
% Fe
%
% EXEMPLES 
% 
% [y,t] = gen_signal();
% [Y,f] = Fourier(y,t);
%
%
% [Y,f] = Fourier();
%
% [Y,f,Fe] = Fourier(y,t);
%
% [Y,f] = Fourier(y,t,'nc');
%===================================================================%

if (nargin ==0)
  [y,t] = Gen_Signal_corr();
  Mode = 'c';
endif

if nargin ==2
  y=varargin{1};
  t = varargin{2};
  Mode = 'c';
endif  


if nargin ==3
  y=varargin{1};
  t = varargin{2};
  Mode = varargin{3};
endif  


N = length(y); 
Fe = 1/(t(2)-t(1));
freq = ((0:N-1)/N)*Fe;

if (Mode == 'c')
  f = [freq(ceil(N/2)+1:N)-Fe freq(1:ceil(N/2))];  
  Y = fftshift(fft(y));
endif
 
if (Mode == 'nc')
  f = freq;
  Y = fft(y);
endif 
 
varargout{1} = Fe;

