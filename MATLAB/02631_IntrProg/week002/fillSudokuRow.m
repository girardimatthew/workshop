function sr = fillSudokuRow(sudokuRow)
assert(length(sudokuRow)==9);
index = sudokuRow==0;
sudokuRow(index) = 45-sum(sudokuRow);
sr = sudokuRow;
end