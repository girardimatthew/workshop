def fillSudokuRow(sudokuRow):
# Fills in a missing entry (marked by zero) in an otherwise
# complete sudoku row. Since a sudoku row must contain all numbers
# from 1 to 9, it must sum to 45. Thus, the missing entry can be
# set to 45 minus the sum of the entries.
    sudokuRow[sudokuRow == 0] = 45 - sum(sudokuRow);
    return sudokuRow