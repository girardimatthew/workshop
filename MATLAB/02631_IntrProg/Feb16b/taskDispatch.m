function assignment = taskDispatch(tasks, units)
%taskDispatch
%   this function takes as input a vector containing the number of required 
%   resources for N tasks as well as a vector containing the number of 
%   available resources for K processing units. The function must return a 
%   vector of length N containing the number of the processing unit 
%   (number between 1 and K) to which each task was assigned according to the algorithm above. 
%   Tasks that have not been assigned to any processing unit (because of lack of resources) should be marked by zero.
%   
%   USAGE:
%   assignment = taskDispatch(tasks, units)
%
%   INPUT
%   - tasks:            The number of resources required for each task (vector).
%   - units:            The total number of available resource for each processing unit (vector)
%
%   OUTPUT
%   - assignment:       Assignment (processing unit number) for each task (vector).
%
K = length(units);
N = length(tasks);
assignment = zeros(1,N);
for k = 1:K
    for n = 1:N
        if units(k) >= tasks(n)
            if assignment(n) == 0
                assignment(n) = k;
                units(k) = units(k) - tasks(n);
            end
        end
    end
end
end