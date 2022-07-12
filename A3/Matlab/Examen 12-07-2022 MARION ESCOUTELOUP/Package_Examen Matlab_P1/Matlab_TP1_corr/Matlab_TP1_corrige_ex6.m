clear ;
clc;

x1 = -10:0.1:-0.1;
x2 = 0.1:0.1:10;
x = cat(2,x1,x2);

y = 1./x;

figure;
plot(x,y);
xlabel('axe x');
ylabel('axe y');
title('fonction y(x)');




