%% Introduction to Programming and Data Processing
% module 007 
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Plotting - Line graphs
clear all; close all; clc;
figure(1);
x = [1 3 4 5];
y = [2 3 3 4];
plot(x, y);
title('Simple line graph');
xlabel('x-values');
ylabel('y-values');
xlim([0, 6]);
ylim([0, 5]);
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Scatter Plot
clear all; close all; clc;
figure(1);
x = [1 3 4 5];
y = [2 3 3 4];
plot(x, y, 'b*');
title('Simple scatter plot');
xlabel('x-values');
ylabel('y-values');
xlim([0, 6]);
ylim([0, 5]);
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Exercise 7A - Cassiopea graph
clear all; close all; clc;
figure(1);
x = [-3 -1 0 3 3];
y = [0 -2 0 -1 2];
plot(x, y, 'b*');
hold on;
plot(x, y, 'r-');
title('Sketch of the Cassiopeia star constalation');
xlabel('relative x value from center star');
ylabel('relative y value from center star');
xlim([-4, 4]);
ylim([-3, 3]);
grid on;
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Exercise 7B - Scatter plot
clear all; close all; clc;
% figure(1);
x = randi([-10 10],1,2000);
y = randi([-10 10],1,2000);
nX = x(max(abs(x),abs(y)) > 5 & sqrt(x.^2 + y.^2) < 10);
nY = y(max(abs(x),abs(y)) > 5 & sqrt(x.^2 + y.^2) < 10);
plot(nY, nX, 'bo');
title('Scatter plot of random numbers');
xlabel('x-values');
ylabel('y-values');
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Exercise 7C - Histograms
clear all; close all; clc;
N = 10;
x = rand(1,N) < 0.5;
figure(1)
subplot(3,1,1);
hist(x,2);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));
% ylabel('Number of heads/tails seen in the sequence');

N = 100;
x = rand(1,N) < 0.5;
subplot(3,1,2);
hist(x,2);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));
ylabel('Number of heads/tails seen in the sequence');

N = 1000;
x = rand(1,N) < 0.5;
subplot(3,1,3);
hist(x,2);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));
% ylabel('Number of heads/tails seen in the sequence');
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% From which of the histograms can you best see that PH = PT = 1/2?
% The first histogram.
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% How would you change the code to generate a sequence of 
%% tosses with an unfair coin, where PH = 0.7 and PT = 0.3?
clear all; close all; clc;
N = 10;
x = rand(1,N) < 0.3;
figure(1)
subplot(3,1,1);
hist(x,2);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));

N = 100;
x = rand(1,N) < 0.3;
subplot(3,1,2);
hist(x,2);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));
ylabel('Number of heads/tails seen in the sequence');

N = 1000;
x = rand(1,N) < 0.3;
subplot(3,1,3);
hist(x,2);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Write a script that simulates a sequence of N throws of a fair six-sided
%% die and plots the distribution of the outcomes in a histogram with 6 bins. 
%% Run your code for N = 10, N = 100 and N = 1000 throws.
clear all; close all; clc;
N = 10;
x = ceil(6 * rand(1, N));
subplot(4,1,1);
hist(x,6);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));

N = 100;
x = ceil(6 * rand(1, N));
subplot(4,1,2);
hist(x,6);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));

N = 1000;
x = ceil(6 * rand(1, N));
subplot(4,1,3);
hist(x,6);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));

N = 10000;
x = ceil(6 * rand(1, N));
subplot(4,1,4);
hist(x,6);
title(sprintf('distribution of H and T in a sequence of N=%d independent fair coin tosses',N));
xlabel(strcat('Head (0)                 Tail (1)'));
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% How large must N be, before the histogram clearly shows that the 
%% probability of each outcome is identical (equal to 1 ).
% .
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Compared to the coin-toss example, why do we in general need a longer 
%% sequence of dice throws to approximate the underlying probability 
%% distribution in the histogram?
% 
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Exercise 7D Radiocarbon dating
clear all; close all; clc;
P = 1000;
nZero = P;
N = [0:P];                                  
tHalf = 5700;                               % every tHalf years the amount of carbon-14 in the dead organic material will be halved
lamba = log(2)/tHalf;                       % decay rate 
t = -1/lamba * log(N/nZero);                % estimated time in years since the organism died.
perc = [0:((P/10)/P):(P/10)];               % percentage from 0% to 100%
figure(1)
plot(perc,t)
title('Carbon-14 decay')
xlabel('Percent of Carbon-14 remaining')
ylabel('Age of material')
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Exercise 7E Temperature in the UK
% This dataset contains yearly temperature information for 
% the United Kingdom, for the years 1912 to 2012 in comma-separated values
% (CSV)format
clear all; close all; clc;
UKtemp = readtable('UKTemperature.csv');
yindx = (UKtemp.Year >= 1920) & (UKtemp.Year <= 2010);
years = UKtemp.Year(yindx);
Meantemp = UKtemp.Average(yindx);
AvgtempM = sum(UKtemp{yindx,2:13}')./12;

fig = figure(1)
plot(years,Meantemp);
hold on;
plot(years,AvgtempM');
title('Yearly temperature development in the UK');
xlabel('Year')
ylabel('Mean temperature (degree Celsius)')
legend('Annual mean','Monthly mean','Location','NorthWest');
print(fig,'UKtemp','-dpng')     % Saving and printing plots
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Working with strings





