function tN = bacteriaGrowth(n0, alpha, K, N)
% bacteria growth function
% Return : Time t at which population size exceeds N (scalar)
% Input: n0 Initial number of bacteria (scalar) 
% alpha Growth rate (scalar)
% K Capacity (scalar)
% N Final population size (scalar, n0<N<K)
% Usage: bacteriaGrowth(no, alpha, K, N)
bG= n0;
tN = 0;
while bG < N
    bG = (1 + alpha * (1 - (bG/K))) * bG;
    tN = tN + 1;
end
end

%% solution
% function tN = bacteriaGrowth(n0, alpha, K, N)
% % Computes the number of hours before a population of bacteria
% % growing according to n(t+1) = (1 + alpha * (1-n(t)/K)) * n(t)
% % exceeds N, starting with n0 bacteria at time t=0
%  
% % Current time step
% t = 0;
%  
% % Population size
% nt = n0;
%  
% % Repeat while population does not exceed N
% while (nt <= N)
%     nt = (1 + alpha*(1 - nt/K)) * nt;
%     t = t+1;
% end
%  
% % Return final time
% tN = t;