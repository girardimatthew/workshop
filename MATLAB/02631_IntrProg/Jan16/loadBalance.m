function k = loadBalance(runtime)
%loadBalance
%   this function takes as input a vector containing the expected runtime 
%   of N workloads (N ? 2). The function must return the number k that 
%   splits the list of workloads as evenly as possible, i.e. such that 
%   the absolute value of the difference between the total expected runtime 
%   of the first k and the last N ? k workloads is as small as possible. 
%   If more than one split results in the same lowest absolute 
%   difference you must return the lowest value of k.
%   
%   USAGE:
%   function k = loadBalance(runtime)
%
%   INPUT
%   - runtime:          Runtime of N workloads (vector)
%
%   OUTPUT
%   - k:                Number of workloads to run on computer 1 (whole number)
%
N = length(runtime);
absDiff = Inf;
for i = 1:N-1
    d = abs(sum(runtime(1:i)) - sum(runtime(i+1:end)));
    if d < absDiff
        absDiff = d;
        k = i;
    end
end
end

% % % Get number of workloads
% % N = length(runtime);
% %  
% % % Reserve space for absolute error
% % absolute_error = zeros(N-1, 1);
% %    
% % % Loop over all possible workload divisions
% % for k = 1:N-1
% %     % Compute absolute difference
% %     absolute_error(k) = abs( sum(runtime(1:k)) - sum(runtime(k+1:N)) );
% % end
% %  
% % % Get the value of k that minimizes absolute error
% % [~, k] = min(absolute_error);