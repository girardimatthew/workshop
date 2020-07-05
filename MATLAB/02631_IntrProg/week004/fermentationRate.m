function averageRate = fermentationRate(measureRate, lowerBound, upperBound)
% fermentation rates function 
% using vectorized computation
measureRate(measureRate <= lowerBound | measureRate >= upperBound) = 0;
measureRate = measureRate(measureRate ~= 0);
averageRate = sum(measureRate)/length(measureRate);
end

%% solution
% function averageRate = fermentationRate(measuredRate, lowerBound, upperBound)
% % Returns average of elements of vector measuredRate greater than
% % lowerBound and less than upperBound
% goodRates = measuredRate > lowerBound & measuredRate < upperBound;
% averageRate = mean(measuredRate(goodRates));