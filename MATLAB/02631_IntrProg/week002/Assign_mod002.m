%% Assignment 2F - Module 002
clear all; close all;
a=[1:5]
computeProjection(a)
a=[-10:0]
computeProjection(a)
a=[2,-1]
computeProjection(a)
a=[1.2]
computeProjection(a)
%% Assignment 2G - Module 002
clear all; close all;
v=[5,20,14,25,12,23,5,17];
boxArea(v,'Intersection')
boxArea(v,'Box1')
boxArea(v,'Box2')
boxArea(v,'Union')
%%
boxArea(-v,'Intersection')
boxArea(v,'Box1')
boxArea(v,'Box2')
boxArea(v,'Union')
%% Assignment 2H - Module 002
clear all; close all;
sr = [9, 4, 0, 1, 5, 7, 2, 3, 8];
fillSudokuRow(sr)
sr = [9 8 6 0 7 1 4 3 2];
fillSudokuRow(sr)

