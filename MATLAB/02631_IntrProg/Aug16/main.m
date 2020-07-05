%% confidence interval
clear all; close all; clc;
x = [1 2 4 3 1];
confidence(x)
x = randi(10,4,1);
confidence(x)
%% Day of the week
clear all; close all; clc;
d = 5;
m = 12;
y = 16;
weekday(d,m,y)
weekday(21, 8, 16)
weekday(21, 9, 16)
%% Matrix symmetrization
clear all; close all; clc;
x = [1.2 2.3 3.4; 4.5 5.6 6.7; 7.8 8.9 10.0]
symmetrize(x)
INTERVAL = [0 10];
size = 5;
x = INTERVAL(1) + (INTERVAL(2)-INTERVAL(1)).*rand(size,size)
symmetrize(x)
%% Volume difference
clear all; close all; clc;
R = 5;
n = 2;
voldif(R,n)
%% String comparison
clear all; close all; clc;
s1 = 'aardvark';
s2 = 'artwork';
stringcompare(s1,s2)
s1 = 'ciccio';
s2 = 'cacca';
stringcompare(s1,s2)

