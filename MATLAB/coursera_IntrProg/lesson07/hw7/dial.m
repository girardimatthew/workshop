function out = dial(str)
    out = [];
    ex = [(33:34),(36:39),(43:44),(46:47),(58:64),81,(90:127)];
    toascii = double(str);
    for jj = 1:length(str)
        out(jj) = 0;
    end
    for ww = 1:length(toascii)
        for nn = 1:length(ex)
            if toascii(ww) == ex(nn)
                out = [];
                return
            end
        end
    end
    
    for ii = 1:length(str)
        if toascii(ii) >= 48 && toascii(ii) <= 57
            out(ii) = toascii(ii);
        elseif toascii(ii) >= 65 && toascii(ii) <= 67
            out(ii) = 50;
        elseif toascii(ii) >= 68 && toascii(ii) <= 70
            out(ii) = 51;
        elseif toascii(ii) >= 71 && toascii(ii) <= 73
            out(ii) = 52;
        elseif toascii(ii) >= 74 && toascii(ii) <= 76
            out(ii) = 53;
        elseif toascii(ii) >= 77 && toascii(ii) <= 79
            out(ii) = 54;
        elseif toascii(ii) >= 80 && toascii(ii) <= 83
                out(ii) = 55;
        elseif toascii(ii) >= 84 && toascii(ii) <= 86
            out(ii) = 56;
        elseif toascii(ii) >= 87 && toascii(ii) <= 89
            out(ii) = 57;
        elseif toascii(ii) == 40 || toascii(ii) == 41 || toascii(ii) == 45
            out(ii) = 32;
        else
            out(ii) = toascii(ii);
        end
    end
    out = char(out);
end