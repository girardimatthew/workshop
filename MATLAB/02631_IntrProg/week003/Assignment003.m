%% Introduction to Programming and Data Processing
% module 003 - Assignments
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Assignment 3C
% Angles between lines
clear all; close all; clc;
v1 = [-4/5, 3/5];
v2 = [20/29, 21/29];
acuteAngle(v1,v2)
acuteAngle([1, 0], [0, 1])
acuteAngle([28/53, 45/53], [5/13, 12/13])
acuteAngle([-4/5, 3/5], [-4/5, 3/5])
acuteAngle([1/3, 2/3, 2/3], [2/7, 3/7, 6/7])
%% Assignment 3D
% Piecewise function.
clear all; close all; clc;
x = 1.78e6;
gravitationalPull(x)
gravitationalPull(7.2e6)
gravitationalPull(6.317e6)
gravitationalPull(0)

x = 0:1e4:10e6;
plot(x, gravitationalPull(x));

%% Assignment 3E
% Acidity
clear all; close all; clc;
pH2Category(11.1)

%% Assignment 3F
% Football goal tracker
clear all; close all; clc;
point = [30, 20];
directionVector = [10, 2];
t0 = computePassesGoalLine(point, directionVector)
t1 = computePassesGoalLine([75, 20], [-10, 2])
t2 = computePassesGoalLine([50, 50], [5, -1])
t3 = computePassesGoalLine([30, 20], [-10, -2])
t4 = computePassesGoalLine([50, 50], [0, 1])