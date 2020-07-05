function arabn = roman(str)
    rom = cell(1,20);
    rom{1} = 'I';
    rom{2} = 'II';
    rom{3} = 'III';
    rom{4} = 'IV';
    rom{5} = 'V';
    rom{6} = 'VI';
    rom{7} = 'VII';
    rom{8} = 'VIII';
    rom{9} = 'IX';
    rom{10} = 'X';
    rom{11} = 'XI';
    rom{12} = 'XII';
    rom{13} = 'XIII';
    rom{14} = 'XIV';
    rom{15} = 'XV';
    rom{16} = 'XVI';
    rom{17} = 'XVII';
    rom{18} = 'XVIII';
    rom{19} = 'XIX';
    rom{20} = 'XX';
    for nn = 1:length(rom)
        if strcmp(rom{nn},str)
            arabn = uint8(nn);
            return
        else
            arabn = uint8(0);
        end
    end
end