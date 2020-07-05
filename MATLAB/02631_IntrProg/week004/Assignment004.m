%% Introduction to Programming and Data Processing
% module 004 - Assignments
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% A4D - Fermentation rate
clear all; close all; clc;
l = 15;
u = 25;
mfr = [20.1 19.3 1.1 18.2 19.7 121.1 20.3 20.0];
fermentationRate(mfr, l, u);
fermentationRate([20.1, 19.3, 1.1, 18.2, 19.7, 121.1, 20.3, 20.0], 1, 200);
fermentationRate([1.75], 1, 2);
fermentationRate([20.1, 19.3, 1.1, 18.2, 19.7, 121.1, 20.3, 20.0], 18.2, 20)
%% A4E - Bacteria growth
clear all; close all; clc;
n0 = 100;              % initial number of bacteria
alpha = 0.4;           % Growth rate
K = 1000;              % Capacity
N = 500;               % Final population size
bacteriaGrowth(n0, alpha, K, N)
bacteriaGrowth(10, 0.4, 1000, 500)
bacteriaGrowth(100, 1.4, 1000, 500)
bacteriaGrowth(100, 0.0004, 1000, 500)
bacteriaGrowth(100, 0.4, 1000, 99)
%% A4F - Removing incomplete experiments
clear all; close all; clc;
id = [1.3 2.2 2.3 4.2 5.1 3.2 5.3 3.3 2.1 1.1 5.2 3.1]
removeIncomplete(id)
removeIncomplete([1.1, 1.2, 1.3, 2.1, 2.2, 2.3])
removeIncomplete([1.1, 1.3, 2.1, 2.2, 3.1, 3.3, 4.1, 4.2, 4.3])
removeIncomplete([5.1, 5.2, 4.1, 4.3, 4.2, 8.1, 8.2, 8.3])
removeIncomplete([1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1, 11.1, 12.1, 13.1, 14.1, 15.1, 16.1, 17.1, 18.1, 19.1, 20.1, 21.1, 22.1, 23.1, 24.1, 25.1, 26.1, 27.1, 28.1, 29.1, 30.1, 31.1, 32.1, 33.1, 34.1, 35.1, 36.1, 37.1, 38.1, 39.1, 40.1, 41.1, 42.1, 43.1, 44.1, 45.1, 46.1, 47.1, 48.1, 49.1, 50.1, 1.2, 2.2, 3.2, 4.2, 5.2, 6.2, 7.2, 8.2, 9.2, 10.2, 11.2, 12.2, 13.2, 14.2, 15.2, 16.2, 17.2, 18.2, 19.2, 20.2, 21.2, 22.2, 23.2, 24.2, 25.2, 26.2, 27.2, 28.2, 29.2, 30.2, 31.2, 32.2, 33.2, 34.2, 35.2, 36.2, 37.2, 38.2, 39.2, 40.2, 41.2, 42.2, 43.2, 44.2, 45.2, 46.2, 47.2, 48.2, 49.2, 50.2, 51.1, 51.2, 51.3])
%% A4G - Cluster analysis
clear all; close all; clc;
% TEST 1
setR = [1.7 1.6 1.3 1.3 2.8 1.4 2.8 2.6 1.6 2.7];
clusterAnalysis(setR)
% TEST 2
clusterAnalysis([1.7, 1.6, 1.3, 1.3, 2.8, 1.4, 2.8, 2.6, 1.6, 2.7, 1.1])
% TEST 3
clusterAnalysis([1.5, 7.8])
% TEST 4
clusterAnalysis([1.1, 1.4, 1.6, 1.2, 1.4, 1.4, 1.8, 28.9, 1.5, 1.2, 7.1])
% TEST 5
clusterAnalysis([10.0, 12.0, 10.0, 12.0, 9.0, 11.0, 11.0, 13.0])


