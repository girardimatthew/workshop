%% Introduction to Programming and Data Processing
% module 002
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Exercise 2C
clear all; close all;
v1 = [1:5]
v2 = [3:7]
v3 = ones(1,4)
%% dot product
dot(v1,v2)
v1*v2'
%% elememt wise
v1.*v2
%% sin function
sin(v1)
%% length of 
length(v1)
%% dot product
v1.*v3
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Exercise 2D
clear all; close all;
v1 = [4, 2, 1, 2, 5]
v2 = [-1, 4, 5, -3, 6]
%% the elements of v1 that are less than 2
v3 = v1(v1<3)
%% the elements of v2 that are negative
v3 = v2(v2<0)
%% the elements of v2 that are greater than zero
v3 = v2(v2>0)
%% the elements of v1 that are greater than 100
v3 = v1(v1>100)
%% the elements of v1 that are greater than the 
% corresponding element of v2
v3 = v1(v1>v2)
%% the elements of v2 that are not equal to 5
v3 = v2(v2~=5)
%% the element of v1 that are greater than the average
% of the elements in v1
v3 = v1(v1>mean(v1))
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Exercise 2E
clear all; close all;
%% set all negative values to zero
v = [4, 7, -2, 9, 3, -6, -4, 1]
v(v<0)=0
%% change the sign of all values
v = [4, 7, -2, 9, 3, -6, -4, 1]
-v
%% set all values that are less than the average to zeros
v = [4, 7, -2, 9, 3, -6, -4, 1]
v(v<mean(v))=0
%% Set all negative values to positive
v = [4, 7, -2, 9, 3, -6, -4, 1]
v(v<0)=-v(v<0)
%% Multiply all positive values by two
v = [4, 7, -2, 9, 3, -6, -4, 1]
v(v>0)=v(v>0)*5
%% Raise all values to the power of 2, 
% but keep their original sign.
v = [4, 7, -2, 9, 3, -6, -4, 1]
i=v<0
v=v.^2
v(i>0)=-v(i>0)
%% Unity test of compute_velocity
clear all; close all;
assert(compute_velocity(0, 0, 0) == 0);
%% No accelleration: Final velocity = initial velocity
assert(compute_velocity(10, 0, 0) == 10);
assert(compute_velocity(5, 0, 5) == 5);
%% No travelled distance: Final velocity = initial velocity
assert(compute_velocity(10, 7, 0) == 10);
%% Positive acceleration and distance: Final velocity is greater than initial velocity
assert(compute_velocity(0, 1, 5) > 0);
assert(compute_velocity(5, 2, 5) > 5);
