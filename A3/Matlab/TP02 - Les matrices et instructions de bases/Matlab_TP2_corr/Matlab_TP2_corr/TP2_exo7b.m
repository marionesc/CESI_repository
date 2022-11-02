tic
N = 10^5;

u = zeros(1,N);
un= 1;

for n=2:N
  un_1 = un;
  un = 0.5*(un_1+16./un_1);
  %u(n) = 0.5*(u(n-1)+16./u(n-1)); 
endfor
toc
