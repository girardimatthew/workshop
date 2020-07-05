function usd = rich(cent)
	usd = [0.01 0.05 0.10 0.25] * cent';
end
 
% We use the fact that matrix multiplication sums up a set of products. 
% Multiplying a row vector with a column vector will result in a scalar. 
% Here it performs the exact calculations we need.
