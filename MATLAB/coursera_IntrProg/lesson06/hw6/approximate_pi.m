function [api, k1] = approximate_pi(delta)
k = 0;
api = 0;
while abs(api - pi) > delta
    api = api + sqrt(12).*(((-3).^-k)./(2*k+1));
    %api = api + sqrt(12)./(  (2*k+1).*(-3).^k  );
    k = k + 1;
end
k1 = k - 1;
end

%(sqrt(12) * ((sum(-3).^-k)/(2*k -1)))

% Not working
% function [pi_here,k1] = approximate_pi(delta)
%     f = @(k)sqrt(12)* sum(1./(  (2*k+1).*(-3).^k  ))  ;
%     k1 = ceil(fzero(@(k)abs(f(0:k) - pi) - delta,1)); 
%     pi_here = f(0:k1);
% end

% Not working
% function [pi_here,k1] = approximate_pi(delta)
%     f = @(k)sqrt(12)* 1./(  (2*k+1).*(-3).^k  )  ;
%     k1 = ceil(fzero(@(k)abs(f(k)) - delta,1)); 
%     pi_here = sum(f(0:k1));
% end