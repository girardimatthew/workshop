function n = one_per_n02(x)
    s = 0;
    for n = 1:1e4
        s = s + 1/n;
        if s >= x
            return;
        end
    end
    n = -1;
end