%% N-best scores
clear all; close all; clc;
nBest([12.5, 13.6, -9.1, 17.5, 15.3, 10.5], 3)
nBest([12.5, 13.6, -9.1, 17.5, 15.3, 10.5], 4)
nBest([12.5, 13.6, -9.1, 17.5, 15.3, 10.5], 2)
nBest([45, 78, 56, 12, 53, 48, 86, 15, 23, 79], 3)
nBest([45, 78, 56, 12, 53, 48, 86, 15, 23, 79], 2)
nBest([45, 78, 56, 12, 53, 48, 86, 15, 23, 79], 1)
nBest([45, 78, 56, 12, 53, 48, 86, 15, 23, 79], 10)
nBest([5.5, 4.4, 1.1, 2.2, 3.3, 6.6], 4)
nBest([5.5, -4.4, 1.1, -2.2, 3.3, -6.6], 2)
nBest([-5.5, -4.4, -1.1, -2.2, -3.3, -6.6], 4)
nBest([-5.5, -4.4, -1.1, -2.2, -3.3, -6.6], 2)
%% Time dilation
clear all; close all; clc;
timeDilation([5, 10.5, 16], [1.1e8, 2.2e8])
timeDilation([5, 10.5, 16], [1.1e8, 2.2e8, 2.9e8, 2.997e8])
timeDilation([5, 10.5, 16, 18.5, 21], [1.1e8, 2.2e8])
timeDilation([5, 10.5, 16, 18.5, 21], [1.1e8, 2.2e8, 2.9e8, 2.997e8])
timeDilation([0, 1, 2, 3, 4], [299000000, 299500000])
timeDilation([4, 3, 2, 1, 0], [299000000, 299500000])
timeDilation([16, 10.5, 5], [2.2e8, 1.1e8])
timeDilation([16, 5, 10.5], [1.8e8, 2.2e8, 1.1e8])
timeDilation([5], [1.1e8, 2.2e8])
timeDilation([5, 10.5, 16], [1.1e8])
timeDilation([5], [1.1e8])
%% Derangements
clear all; close all; clc;
for i = 1:12
    derangements(i)
end
%% Industrial classification
clear all; close all; clc;
industry('35xx')
industry('0xxx')
industry('1499')
industry('2xxx')
industry('9x00')
%% Task dispatch
clear all; close all; clc;
taskDispatch([5, 7, 4, 2, 3, 5], [11, 13])
taskDispatch([5, 7, 4, 2, 3, 5], [7, 7, 7])
taskDispatch([5, 7, 4, 2, 3, 5], [100, 10, 1])
taskDispatch([6, 5, 6, 5], [12, 10])
taskDispatch([1, 5, 7, 6, 5, 4, 8, 6, 1], [5, 10, 15])
taskDispatch([1, 5, 7, 6, 5, 4, 8, 6, 1], [15, 10, 5])
taskDispatch([1, 5, 7, 6, 5, 4, 8, 6, 1], [15, 10, 5])
taskDispatch([75], [75])