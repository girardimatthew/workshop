%% Introduction to Programming and Data Processing
% module 006
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all; close all; clc;
A = [1 2 3; 4 5 6]
size(A)
min(A,[],1)
min(A,[],2)
min(A,3)
sum(A,1)
sum(A,2)
A(2,1)
A(2,:)
A(:,3)
A(:,2:3)
A'
A = 1:6
A = reshape(A,2,3)
A = reshape(A,3,2)
A = reshape(A,3,2)'
A = [1 2 3; 4 5 6];
B = [7 8; 9 10];
AB = [A,B]
C = 11:19
C = reshape(C,3,3)
AC = [A;C]
b = [3;2;1]
A*b
A.*A
%% 
clear all; close all; clc;
x = 1:5;
y = sin(x);
save('saved.mat','x','y');
clear all;
load('saved.mat');
x
y
%% String Manipulation
clear all; close all; clc;
word = char('northeast');
v1 = word(1:5);
v2 = word(6:end);
v3 = char(v1,v2)
%% 
clear all; close all; clc;
blanks(4)
blanks(4)'          % move down the cursor.
sent1 = sprintf('The value of pi is %.2f', pi)
sent2 = sprintf('A random integer %d !!!', randi([5,10]))
%% Customized Strings
clear all; close all; clc;
x = [123  4.4  5.6  2.5  7.2  4.6  5.3];
save('expnoanddata.mat','x');
clear all; close all; clc;
load expnoanddata.mat 
experNo = x(1);
data = x(2:end);
plot(data,'ko')
xlabel('Sample #');
ylabel('Weight');
title(sprintf('Data from experiment %d', experNo));
%% Exercise 6A - Loading and saving variables
clear all; close all; clc;
pwd
ls 
load smooth.mat
figure(1)
plot(x,y);
title('Exercise 6A 001')
newX = x;
newY = 1 - y;
figure(2)
plot(newX,newY);
title('Exercise 6A 002')
save('newSmooth.mat','newX','newY');
%% 
clear all; close all; clc;
load newSmooth.mat
figure(1)
plot(newX,newY);
%% Converting vectors into Matrix
clear all; close all; clc;
a = [1:6]
A = reshape(a,2,3)
Atr = reshape(a,3,2)'
b = A(:)
bpr = b'
%%
clear all; close all; clc;
a = [1:6]
A = reshape(a,2,3)
min(A,[],1)
min(A,[],2)
sum(A,1)
sum(A,2)
%% Matrix multiplication
clear all; close all; clc;
a = [1:3;4:6];
b = [3:-1:1]';
mult = a*b;
%% Working with CSV files.
clear all; close all; clc;
topscorers = readtable('topscorers_small.csv');
% table
topscorers
topscorers.Properties.VariableNames
% Goals
topscorers.Goals
% the number of minutes played per goal scored
topscorers.MinutesPlayed./topscorers.Goals
% names
topscorers.Player
topscorers(:,4)     % a table
topscorers{:,4}     % a vector
topscorers(2,:)     % a table
topscorers{:,3}     % a vector






