function itemCost = computeItemCost(resourceItemMatrix, resourceCost)
% computes the cost of each item and returns it as a vector.
% INPUT
% resourceItemMatrix    :   A matrix describing how many units of each resource is required for each item.
% resourceCost          :   Vector of the cost of each resource.
% OUTPUT
% itemCost              :   Vector of the cost of each item.
itemCost = (resourceItemMatrix'*resourceCost')';
end

% Compute the cost of each item using a vector-matrix product
% itemCost = resourceCost * resourceItemMatrix;