%% Introduction to Programming and Data Processing
% module 004
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% for-loop
clear all; close all; clc;
for i = 0:3
    disp(i)
end
minNumber = 10;
maxNumber = 20;
for i = minNumber:maxNumber
    disp(i);
end
%% while-loop
clear all; close all; clc;
theSum = 0;
i = 1;
while theSum < 3
    theSum = theSum + 1 / i;
    disp(theSum);
    i = i + 1;
end
%% breaking a loop
clear all; close all; clc;
theSum = 0;
i = 1;
while true
    theSum = theSum + 1 / i;
    if theSum >= 3 
        break;
    end
    disp(theSum);
    i = i + 1;
end
%% vectorized computation and loops
clear all; close all; clc;
x = [-2, -1, 0, 1, 2];
for i = 1:5
    if x(i) < 0
        x(i) = 0;
    else
        x(i) = x(i) * 2;
    end
end
x
x = [-2, -1, 0, 1, 2];
x(x < 0) = 0;
x = x * 2;
x
%% Displaying formatted output
clear all; close all; clc;
x = pi;
fprintf('The cosine of %f is %f\n', x, cos(x));
%% Exercise 4A - 1
clear all; close all; clc;
for i = 1:10
    fprintf('%d I love programming!\n', i);
end
%% Exercise 4A - 2
clear all; close all; clc;
x1 = 2;
xl = x1 - 1;
for i = 1:10
    x1 = xl * 2;
    fprintf('%d\n', x1);
    xl = x1;
end
%% Exercise 4A - 3
clear all; close all; clc;
x1 = 13.00;
x2 = 13.16;
while x1 < 20.00
   fprintf('The S-train from Nørreport %2.2f arrives in Lyngby at %2.2f\n', x1, x2);
   x1 = x1 + 0.20;
   x2 = x2 + 0.20;
end
%% Exercise 4B - 1 Power series approximation
% the easiest way, but slower even if N = 100;
clear all; close all; clc;
tic;
%N = 100;
%N = 1000000; % try this
N = 10000000; % try this
sum = 0;
for n = 0:N
    s = ((-1)^n)/(2*n + 1);
    sum = sum + s;
    pi = 4 * sum;
end
pi
toc;
%% Exercise 4B - 2 Power series approximation
% the tricky way, but way more faster
clear all; close all; clc;
tic;
%N = 100;
%N = 1000000; % try this
N = 10000000; % try this
x = (-1).^[0:N];
y = [1:2:(N+1)*2];
x = x./y;
pi = 4 * sum(x)
toc;
% Considering MATLAB, there is a significant speed difference between 
% these two implementations.
%% Exercise 4C - 1 square roots
clear all; close all; clc;
sqrt2 = sqrt(2)
a = 2;
x = a / 2;
N = 3;
for i = 1:N
    x = (x+(a/x))/2;
end





    
    