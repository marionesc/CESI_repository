tic
t = 0:0.01:10;
y = sin(t);
N = length(y);
dt = t(2)-t(1);

for i = 1:N-1

  yd(i)= (y(i+1)-y(i))./dt;
   
endfor

toc;
