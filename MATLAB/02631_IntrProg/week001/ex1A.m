%% Ex 1A - 1
clear all; close all;
a=3;
a+2;
ans+2;
% ans is euqal to 7
%% Ex 1A - 2
a=a+2;
% a is equal to 5
% ans is equal to 7
% the old value of 'a' is lost.
%% Ex 1A - 4
x=4;
y=7;
z=x+y;
%% 
a=7;
b=a;
a=9;
% b is equal to 7
%% Ex 1B - 1
clear all; close all;
a=9/2+2;
b=6+4*4;
c=4/6+2;
d=2-3*2-4;
f=(7-5)*(7+5);
g=(3*(4-2*(3)+4));
%% Ex 1B - 2
clear all; close all;
a=2^3;
b=3^2-4^2;
c=2^2^3;
d=2^(2^3);
%% Ex 1B - 3
clear all; close all;
a=3*(2+3^2);
b=4^2+3^3+2^4+1;
c=1/(1/2+1/3+1/6);
%% Ex 1C - 1
clear all; close all;
%help sin;
a=sin(0.5*pi);
b=sin(90);
%% Ex 1C - 2
clear all; close all;
a0=floor(2.5);
a1=fix(2.5);
a3=floor(2.5)==fix(2.5);
b0=ceil(-3.6);
b1=fix(-3.2);
b2=ceil(-3.6)==fix(-3.2);
c0=round(3.4);
c1=ceil(3.4);
c2=round(3.4)==ceil(3.4);
d0=round(-3.4);
d1=ceil(-3.4);
d2=round(-3.4)==ceil(-3.4);
%% Ex 1C - 3
clear all; close all;
n=1234.56789;
a0=round(n,3);
a1=round(n,1);
a3=round(n);
a4=round(n,-2);
%% Ex 1C - 4
clear all; close all;
help log
%% Ex 1D - 1
clear all; close all;
a0=pi;
a1=sqrt(25);
A=30;
radius=sqrt(A/pi);
%% Ex 1D - 2
clear all; close all;
a0=51;
b0=log(a0);
a1='fiftyone';
% b1=log(a1); %-error
%% Ex 1E - 1
clear all; close all;
x=4;
y=7;
z=x+y;
