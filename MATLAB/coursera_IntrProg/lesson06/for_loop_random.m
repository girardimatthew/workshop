function o = for_loop_random(n)
    for x = rand(1,n); % assign a row vector of random number
        if x > 0.5
            fprintf('Random number %f is large.\n', x);
        else
            fprintf('Random number %f is small.\n', x);
        end
    end
end