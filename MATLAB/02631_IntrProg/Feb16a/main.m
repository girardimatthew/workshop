%% Robust temperature average
clear all; close all; clc;
weeklyAverage([17.3, 18.2, 31.2, 14.2, -12.5, 16.5, 14.2])
weeklyAverage([10.6, -0.4, 35.8, 35.1, 11.4, -9.1, 20.2])
weeklyAverage([43.0, 17.8, 7.9, 25.8, 18.3, 41.3, 38.2])
weeklyAverage([34.6, 12.3, 14.3, 5.4, 3.2, 9.0, 12.8])
%% Car rental
clear all; close all; clc;
carsAvailable([5, 0, 17, 13, 11, 1], 'Lux')
carsAvailable([5, 0, 17, 13, 11, 1], 'Eco')
carsAvailable([5, 0, 17, 13, 11, 1], 'Mini')
carsAvailable([5, 0, 17, 13, 11, 1], 'fullsize')
carsAvailable([70, 60, 50, 40, 30, 20], 'cstandard')
carsAvailable([5, 0, 17, 13, 11, 1], 'void')
%% Speed of light
clear all; close all; clc;
speedOfLight(2.45e9, [0.122, 0.125, 0.123])
%% Similarity matrix
clear all; close all; clc;
similarityMatrix([1.1, 1.2], [1.3, 1.4, 1.5], 2)
similarityMatrix([1.1], [1.3, 1.4, 1.5], 6)
similarityMatrix([1], [1], 1)
similarityMatrix([1.1, 1.2, 1.3], [1.3, 1.4, 1.5], 2)
similarityMatrix([1.1, 1.2, 1.3], [1.3, 1.4, 1.5, 1.6], 1.25)
similarityMatrix([1.3, 1.4, 1.5, 1.6], [1.1, 1.2, 1.3], 3)
%% Coin return
clear all; close all; clc;
coinReturn([0.5, 1, 2, 5, 10, 20], 34.60)
coinReturn([0.5, 1, 2, 5, 10, 20], 134.60)
coinReturn([0.5, 1, 2, 5, 10, 20], 69.50)
coinReturn([0.5, 1, 2, 5, 10, 20], 38.5)
coinReturn([0.5, 1, 2, 5, 10, 20], 77)
coinReturn([0.5, 1, 2, 5, 10, 20, 50, 100], 7523.10)
coinReturn([1, 2, 5, 10, 20], 35.10)
coinReturn([0.5, 1, 5, 10], 36.60)
coinReturn([10, 100, 1000], 10101)
coinReturn([10, 100, 1000], 12343)
coinReturn([10], 42)