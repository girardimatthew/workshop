%% Introduction to Programming and Data Processing
% module 006 - Assignments
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Assignment 6B Production cost
clear all; close all; clc;
rItMtrx = [6, 3, 0; 17, 11, 9; 4, 2, 12];
rCost = [101.25, 84.00, 75.50];
computeItemCost(rItMtrx, rCost)
%% Assignment 6C Moving average
% One algorithm of smoothing a signal is the n-sample symmetric weighted moving average
clear all; close all; clc;
% movingAvg([0.8, 0.9, 0.7, 0.6, 0.3, 0.4])   % 0.5444    0.7000    0.6889    0.5667    0.4000    0.2667
% movingAvg([0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7])   % 0.1111    0.2000    0.3000    0.4000    0.5000    0.5111    0.4222
% movingAvg([1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0])
% 0.6667 0.8889 1.0000 1.1111 1.3333 1.6667 1.8889 0.6667 0.8889 1.0000 1.1111 1.3333 1.6667 1.8889 2.0000 1.7778 1.3333 2.0000 1.7778 1.3333
% movingAvg([1.0]) % 0.3333
%% Plotting smooth signal
clear all; close all; clc;
load smooth.mat
plot(x, sin(x),'k');
hold on;
plot(x, y,'g.');
plot(x, movingAvg(y),'r.-');
legend('sin(x)','y','movingAvg(y)');
%% Assignment 6D Frequency of letters
clear all; close all; clc;
txtFile = 'small_text.txt';
freq = letterFrequency(txtFile)
save('letterFrequency.mat','freq');
%% Assignment 6E Language detection
clear all; close all; clc;
load letterFrequency.mat
computeLanguageError(freq)
%% Exercise 6F Advanced file types
% audiofile
clear all; close all; clc;
[Y, FS] = audioread('data/lucy.wav');
% sound(Y,FS)
line = linspace(0,0,length(Y));

% Plotting
figure(1)
plot(Y);
xlabel(sprintf('Time: %.2f sec', length(Y)/FS));
ylabel('Amplitude');
title('lucy.wav');
hold on;
plot(line,'r');
legend('waveform','0 line');

nY = lowpass(Y,0.1,0.5)
plot(nY,'g');
sound(nY)
%% Exercise 6F Advanced file types
% .xls Excel file
clear all; close all; clc;
[num,txt,raw] = xlsread('data/employees.xls')
%% Exercise 6F Advanced file types
% .json
clear all; close all; clc;
fname = 'data/employees.json';
fid = fopen(fname);
raw = fread(fid,inf);
str = char(raw');
fclose(fid);

%% Exercise 6F Advanced file types
% .xml
clear all; close all; clc;
xDoc = xmlread('data/employees.xml')
%% Exercise 6F Advanced file types
% .jpg
clear all; close all; clc;
%% Exercise 6F Advanced file types
% .png
clear all; close all; clc;






