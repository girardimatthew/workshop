%% Pages in a booklet
clear all; close all; clc;
for i = 0:20
    bookPages(i)
end
%% Load balancing
clear all; close all; clc;
loadBalance([5, 2.5, 17, 1.5, 22, 3.5])
loadBalance([5, 78, 5, 78, 5, 78, 5, 78])
loadBalance([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1])
loadBalance([5, 5000, 5])
loadBalance([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
loadBalance([10, 5])
loadBalance([29.2, 43.2, 1.5, 98.4, 16.7, 10.6, 37.2])
loadBalance([1000000, 1, 1, 1, 1, 1, 1, 1])
loadBalance([66.0, 51.9, 97.3, 64.9, 80.0, 45.4, 43.2, 82.5, 8.3, 13.3])
loadBalance([4, 9, 9, 5, 5, 3, 9, 4, 1, 8, 4, 2, 4, 1, 1, 9, 10, 6, 1, 2, 4, 8, 2, 6, 7, 6, 5, 5, 3, 7, 2, 7, 2, 4, 6, 8, 1, 9, 8, 5, 4, 4, 3, 5, 5, 8, 8])
%% Nearest color
clear all; close all; clc;
nearestColor(75,0,0) % Red
nearestColor(75, 77, 80) % White
nearestColor(100, 100, 0) % Yellow
%% Mountain climb categorization
clear all; close all; clc;
climbCategorization(8, 6)
climbCategorization(2, 1)
climbCategorization(12, 2)
climbCategorization(8, 7)
climbCategorization(14, 5)
climbCategorization(14, 6.9)
%% Roman numerals
clear all; close all; clc;
romanToValue('XCIV')
romanToValue('XXXVI')
romanToValue('MMXII')
romanToValue('MCMXCVI')
romanToValue('MCMLIV')
romanToValue('MMLIX')
romanToValue('MDCLXVI')
romanToValue('MMDCCLXXVII')
romanToValue('MCMLXXXIV')
romanToValue('MMXVI')
romanToValue('MCMXCVIII')
romanToValue('IIIIIVXX')
romanToValue('VICVICM')
romanToValue('LLC')