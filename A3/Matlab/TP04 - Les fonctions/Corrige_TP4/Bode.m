function [varargout] = Bode(varargin);

%============================================================================%
% FONCTION RETOURNANT LE DIAGRAMME DE BODE D'UN FILTRE    
% [H,f] = Bode(1,'bas', 50,1024,1e3)
%
% ENTREES 
% ordre du filtre : 1 ou 2  [1]
% type de filtre : passe-bas ('bas') / passe-haut 'haut'  ['bas']
% fc  : frequence de coupure  [50]
% N : Nombre de points de la fonction de transfert [1024]
% Fe : fréquence d'échantillonnage (Hz) [1khz]
% 
% SORTIES
% H   :  Fonction de transfert complexe
% f   :  frequence en Hz
% 
%
%
% EXEMPLES 
% 
% Diagramme de Bode par defaut : ordre = 1, filtre passe bas, fc = 50; N = 1024, Fe = 1000
% [H,f] = Bode();
%
%  Passe bas du premier ordre, fc = 100 Hz, 1024 echantillons, Fe=5khz
% [H,f] = Bode(1,'bas',100,1024,5e3);
%
%  Passe haut second ordre, fc = 250 Hz, 1024 échantillons, Fe = 5khz
% [H,f] = Bode(2,'haut',250,1024,5e3);
%
%===================================================================%

if (nargin ==0)
  ordre =  ???;
  type = ???;
  fc =  ????;
  N =  ????;
  Fe =  ????;
endif

if (nargin > 0)
   ordre = ????????;
   type = ?????????;
   fc = ??????????;
   N = ??????????;
   Fe = ???????????;
endif

f= ((0:N-1)/N)*Fe/2;
w = 2*pi*f;
wc = 2*pi*fc;


if  (strcmp(type,'bas') )
  
  if (ordre == 1)
  
      H = ??????????
  end
  
  if (ordre ==2)
     amor = (sqrt(2)/2);
     H = 1./(1+2*amor*j*w./wc+(j*w./wc).^2);
     
  end
  
endif


if  (strcmp(type,'haut')) 
  
  if (ordre == 1)
  
       H = ????????????
  end
  
  if (ordre ==2)
     amor = (sqrt(2)/2);
     H = (j*w./wc).^2./(1+2*amor*j*w./wc+(j*w./wc).^2);
     
  end
  
endif

figure;
subplot(2,1,1);
semilogx(f(2:N),20*log10(abs(H(2:N))));
xlabel('Frequences (Hz)');
title('Module du filtre');
subplot(2,1,2);
semilogx(f(2:N),angle(H(2:N)));
xlabel('Frequences (Hz)');
title('Phase du filtre');

 
varargout{1} = ????????????
varargout{2} = ????????????

