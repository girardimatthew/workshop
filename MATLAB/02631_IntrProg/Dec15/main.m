%% Conversion of grades
clear all; close all; clc;
convertGrade(13,'13-scale')
convertGrade(12,'13-scale')
convertGrade(12,'7-point')
convertGrade(11,'7-point')
convertGrade(11,'8-point')
%% When to hire an employee
clear all; close all; clc;
hireApplicant(8,7)
hireApplicant(8,9)
%% Average hearing loss
clear all; close all; clc;
M = [25 25 30 40 40 40 45; 50 55 55 65 65 70 75; 75 70 70 70 50 50 55; 25 30 35 40 50 55 60];
averagedB(M)
averagedB([25 25 30 40 40 40 20;50 55 55 65 65 70 20;75 70 70 70 50 50 20;25 30 35 40 50 55 20])
averagedB([50 55 55 65 65 70 75;75 70 70 70 50 50 55;25 30 35 40 50 55 60])
averagedB([25 30 35 40 50 55 60; 25 30 35 40 50 55 75])
averagedB([15 15 20 30 30 30 70; 40 45 45 55 55 60 65; 65 60 60 60 40 40 45; 15 20 25 30 40 45 80])
averagedB([15 15 20 30 30 30 70;  65 60 60 60 40 40 45; 15 20 25 30 40 45 80])
%% Building LEGO bricks
clear all; close all; clc;
buildLego(1,8,1.6)
buildLego(1,1,1)
buildLego(5,5,5)
%% Sudoku check
clear all; close all; clc;
sB = [5 3 4 6 7 8 9 1 2;...
    6 7 2 1 9 5 3 5 8;...
    1 9 8 3 4 2 4 6 7;...
    8 5 9 7 6 1 4 2 3;...
    4 2 6 8 5 3 7 9 1;...
    7 1 3 9 2 4 8 5 6;...
    9 6 1 5 3 7 2 8 4;...
    2 8 7 4 1 9 6 3 5;...
    3 4 5 2 8 6 1 7 9;];
sudokuCheck(sB)
sB = zeros(9,9);
sudokuCheck(sB)
sB = [1:9; 1:9; 1:9; 1:9; 1:9; 1:9; 1:9; 1:9; 1:9];
sudokuCheck(sB)
 

