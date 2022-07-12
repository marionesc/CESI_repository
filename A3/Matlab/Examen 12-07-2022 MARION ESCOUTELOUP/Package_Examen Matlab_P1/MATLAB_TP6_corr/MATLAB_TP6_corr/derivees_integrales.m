############ Realisation de la dérivée  ######
h = 0.001;
x = -pi:h:pi;
y = sin(x);


### derivee premiere

yp = diff(y)./h;

figure; 
plot (x,y,'b',x(1:length(yp)),yp,'r');


### derivee seconde 

ys = diff(yp)./h;
figure;
plot(x,y,'b',x(1:length(ys)),ys,'r');


####### Realisation de l'integrale ######

#### Cumtrapz(x,y) = F(x) - F(xmin) => F(x) = Cumtrapz(x,y) + F(xmin)
yi = cumtrapz(x,y)+(-cos(-pi));

figure;
plot(x,y,'b',x(1:length(yi)),yi,'r');


