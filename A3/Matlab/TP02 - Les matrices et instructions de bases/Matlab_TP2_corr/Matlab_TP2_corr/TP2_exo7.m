tic
N = 10^5;
a = 16;
u = zeros(1,N);
u(1)= 1;
for n=2:N
  u(n) = 0.5*(u(n-1)+a./u(n-1)); 
endfor
toc
