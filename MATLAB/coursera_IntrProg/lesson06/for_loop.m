function f = for_loop(n)
    total = 0;
    for i = 1:n
        total = total + i;
    end
    fprintf('Total equals %d\n', total);
end