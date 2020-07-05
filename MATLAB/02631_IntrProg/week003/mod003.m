%% Introduction to Programming and Data Processing
% module 003
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% EX 3A
clear all; close all; clc;
% case 1.
if false 
    disp('1-Condition is true')
else
    disp('1-Condition is false')
end
% case 2.
x = 10;
if x < 5
    disp('2-Condition is true')
else
    disp('2-Condition is false')
end
% case 3.
x = 5;
if true && x == 5
    disp('3-Condition is true')
else
    disp('3-Condition is false')
end
% case 4.
if false || 5 == 5
    disp('4-Condition is false')
else
    disp('4-Condition is true')
end
% case 5.
if 0
    disp('5-Condition is false')
else 
    disp('5-Condition is true')
end
% case 6.
if 44
    disp('6-Condition is false')
else 
    disp('6-Condition is true')
end
% case 7.
if ''
    disp('7-Condition is false')
else 
    disp('7-Condition is true')
end
% case 8.
if 'hello'
    disp('8-Condition is false')
else 
    disp('8-Condition is true')
end
% case 9.
if 'false'
    disp('9-Condition is false')
else 
    disp('9-Condition is true')
end
% case 10.
if [1, 0]
    disp('10-Condition is false')
else 
    disp('10-Condition is true')
end
%% EX 3B
clear all; close all; clc;
if 9 > 3*3
    disp('1-Condition is true')
else
    disp('1-Condition is false')
end
if 9 >= 3*3
    disp('2-Condition is true')
else
    disp('2-Condition is false')
end
if (6+3) == 3^2
    disp('3-Condition is true')
else
    disp('3-Condition is false')
end
if (12/5) > (17/5)
    disp('4-Condition is true')
else
    disp('4-Condition is false')
end
if (2>3) || (3^2~=9)
    disp('5-Condition is true')
else
    disp('5-Condition is false')
end
if 323~=17*9
    disp('6-Condition is true')
else
    disp('6-Condition is false')
end
if cos(3*pi) < 0
    disp('7-Condition is true')
else
    disp('7-Condition is false')
end