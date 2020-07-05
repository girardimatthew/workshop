function stock = cumulativeStock(transactions)
%cumulativeStock
%   this function returns the number of items in stock after 
%   each transaction given a vector containing the list of transactions
%   
%   USAGE:
%   stock = cumulativeStock(transactions)
%
%   INPUT
%   - transactions:     Transactions (vector of whole numbers)
%
%   OUTPUT
%   - stock:            Number of units in stock after each transition (vector of whole numbers).
%
stock = zeros(1,length(transactions));
stock(1) = transactions(1);
for i = 2:length(transactions)
    if transactions(i) == 0
        stock(i) = 0;
    else
        stock(i) = stock(i-1) + transactions(i);
    end
end   
end