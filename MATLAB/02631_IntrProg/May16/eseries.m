function f = eseries(x, N)
f = 0;
for i = 0:N-1
    f = f + x.^i/factorial(i);
end
end

%% suggested solution
% function f = eseries(x, N)
%  
% % Define i = 0..N-1
% i = 0:N-1;
%  
% % Compute series expansion
% f = sum(x.^i ./ factorial(i));