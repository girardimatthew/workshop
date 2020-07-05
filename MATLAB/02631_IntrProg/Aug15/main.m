%% Body mass index
clear all; close all; clc;
h = 1.85;
w = 75;
classifyBMI(h,w)
%% Stock management
clear all; close all; clc;
t = [10, -4, -3, 10, -12, 0, 8];
cumulativeStock(t)
t = [0, 4, -3, 10, 0, 15, -8];
cumulativeStock(t)
%% Reverse Polish notation calculator
clear all; close all; clc;
RPNCalculator('1 2 3 4 5 s + s + s +')
RPNCalculator('0 11 s 12 s 13 s 14 s')
RPNCalculator('1 2 3 4 5 s - + 17 s - s - + 5 s - 2 3 +')
RPNCalculator('1 2 3 4 5 6 7 8 9 + + + + + + + +')
commands = '2 10 17 - s';
RPNCalculator(commands)
commands = '2 10 17 + s';
RPNCalculator(commands)
commands = '2 10 -';
RPNCalculator(commands)
commands = '5 1 2 + 4 x + 3 -';
RPNCalculator(commands)
commands = '3 4 +';
RPNCalculator(commands)
commands = '3 4 5 x -';
RPNCalculator(commands)
commands = '1 2 + 4 x 5 + 3 -';
RPNCalculator(commands)
commands = '1 -';
RPNCalculator(commands)
%% Star area
clear all; close all; clc;
starPoints(2,1,6.1)
starPoints(2,1,5.5)
starPoints(2,1,5.7)
%% Removing rows and columns
clear all; close all; clc;
M = [1 2 3 4 5; 6 0 8 9 10; 11 12 13 14 15; 16 0 0 19 20];
matrixCleanup(M)
M = [0 2 3 4 5; 6 0 8 9 10; 11 12 13 14 15; 16 0 0 19 20];
matrixCleanup(M)
M = [1 2 3 4; 0 6 7 8; 9 10 11 0];
matrixCleanup(M)
M = [1 2 3 4; 0 6 7 8; 9 10 11 12];
matrixCleanup(M)
M = zeros(4,4);
matrixCleanup(M)
M = [0 1 2 3; 4 5 6 7; 8 9 10 0];
matrixCleanup(M)