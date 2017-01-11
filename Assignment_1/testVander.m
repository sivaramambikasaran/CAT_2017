clear all;
clc;
n       =   10;
% x       =   linspace(-1,1,n);
x       =   cos((0.5:1:n-0.5)*pi/n);
V       =   fliplr(vander(x));
bexact  =   rand(n,1);
a       =   V\bexact;
b       =   V*a;
plot(bexact,'r+');
hold on
plot(b,'b-');