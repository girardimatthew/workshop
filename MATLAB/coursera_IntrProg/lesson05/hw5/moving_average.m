function out = moving_average(x)
persistent average
persistent count
persistent index

if isempty(count)
    count = 1;
elseif count == 25
    count = 25;
else
    count = count + 1;
end

if isempty(index)
    index = 1;
elseif index == 25
    index = 1;
else
    index = index + 1;
end

if isempty(average)
    average = zeros(1,25);
end

average(1,index) = x;
out = sum(average)/count;

%fprintf('count: %d\n', count);
%fprintf('index: %d\n', index);

end



