%% Introduction to Programming and Data Processing
% module 005
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Temperature conversion
clear all; close all; clc;
convertTemperature(50,  'Fahrenheit', 'Celsius')
convertTemperature(50,  'Fahrenheit', 'Kelvin')
convertTemperature(50,  'Celsius', 'Fahrenheit')
convertTemperature(50,  'Celsius', 'Kelvin')
convertTemperature(50,  'Kelvin', 'Celsius')
convertTemperature(50,  'Kelvin', 'Fahrenheit')
%% Input from the user
clear all; close all; clc;
name = input('Please enter your name:  ','s')
%%
clear all; close all; clc;
while true 
    len = str2double(input('Enter the length in meters:  ','s'));
    if ~isnan(len)
        break;
    end
    disp('Not valid number. Please try again');
end
%%
clear all; close all; clc;
len = str2double(input('Enter the length in meters:  ','s'))
%%
clear all; close all; clc;
inputNumber('Enter the length in meter: ')
%% Exercise 5B - Simple menu
clear all; close all; clc;
data = ['ciccio'; 'matteo'; 'aaaaaa'; 'merda '];
celldata = cellstr(data);
choice = displayMenu(celldata);
celldata(choice)
%% Exercise 5C - Interactive temperature calculator
clear all; close all; clc;
interactiveTempConv
%% Exercise 5D - Random Numbers
clear all; close all; clc;
N = 10;
mRA = zeros(1,N);
for i = 1:N
    r = randomSequence(5,3,10);
    mR = mean(r);
    mRA(i) = mR;
end
mRB = zeros(1,N);
for i = 1:N
    r = randomSequence(5,3,100);
    mR = mean(r);
    mRB(i) = mR;
end
mRC = zeros(1,N);
for i = 1:N
    r = randomSequence(5,3,1000);
    mR = mean(r);
    mRC(i) = mR;
end
mRD = zeros(1,N);
for i = 1:N
    r = randomSequence(5,3,10000);
    mR = mean(r);
    mRD(i) = mR; 
end
%% Standard deviation
stdMRA = std(mRA);
stdMRB = std(mRB);
stdMRC = std(mRC);
stdMRD = std(mRD);
%% Plotting
v = [1:N];
figure(1)
plot(v,mRA); hold on;
plot(v,mRB,'--');
plot(v,mRC,':');
plot(v,mRD,'-');
title('mean of Randon numbers')
xlabel('No. of test')
ylabel('mean')
legend('r10','r100','r1000','r10000')
%% 
