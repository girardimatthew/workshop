function stateTime = acState(state, timeStamp)
%acState
%   this function returns the number of seconds the system has been 
%   in each of the five states, measured from the first logged state 
%   until the last logged state change. Input to the function is a 
%   vector of N state codes and a vector of same length with the 
%   corresponding time stamps. 
%   The function must work for vectors of any length N.
%
%   USAGE:
%   stateTime = acState(state, timeStamp)
%
%   INPUT
%   - state:                State code (vector of length N)
%   - timeStamp:            Time stamp (vector of length N)
%
%   OUTPUT
%   - stateTime:            Number of seconds system has been in each 
%                           of the five states (vector of length 5).
%
dur = diff(timeStamp);
stateTime = zeros(1,5);
for i = 0:4
    stateTime(i+1) = sum(dur(state(1:end-1) == i));
end
end