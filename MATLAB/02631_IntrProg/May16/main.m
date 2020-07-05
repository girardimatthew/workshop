%% Exponential series expansion
clear all; close all; clc;
x = 1;
N = 5;
eseries(x,N)
%% Alpha to phone number
clear all; close all; clc;
alpha = '4525DTU1';
alphaToPhone(alpha)
alpha = 'CACCA';
alphaToPhone(alpha)
alpha = '1ADGJMPTW0';
alphaToPhone(alpha)
%% Guess the gender
clear all; close all; clc;
name = 'affonso';
genderGuess(name)
name = 'michela';
genderGuess(name)
name = 'matteo';
genderGuess(name)
name = 'giovanni';
genderGuess(name)
%% Birthday problem
clear all; close all; clc;
n = 2;
birthday(n)
%% Matrix search
clear all; close all; clc;
A = [1 2 6 10; 3 7 7 13; 7 9 11 14];
x = 3;
matrixSearch(A,x)
%%
function index = matrixSearch(A, x)
 
% Matrix dimensions
[M, N] = size(A);
 
% Initial position
i = 1;
j = N;
 
% Continue while we have not found x
while A(i,j) ~= x
   if A(i,j) > x
      % Move left
      j = j - 1;
   else
      % Move down
      i = i + 1;
   end
   % Check if we are outside matrix
   if i > M || j < 1
      i = 0;
      j = 0;
      break;
   end
end
 
% Collect i and j in vector
index = [i j];


