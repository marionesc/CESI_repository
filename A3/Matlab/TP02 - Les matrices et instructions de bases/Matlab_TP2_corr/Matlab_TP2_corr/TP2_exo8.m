tic
t = 0:0.01:10;
y = sin(t);
N = length(y);

dt = t(2)-t(1);
yd= (y(2:N)-y(1:N-1))./dt;
%yd(1) = (y(2) - y(1))./dt
%yd(2) = (y(3) - y(2))./dt
toc;
