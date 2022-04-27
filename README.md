# Sudoku Solver in C++

Works for any correct Sudoku, otherwise it will display an error message.
- 0 = empty space
- numbers must contain spaces between them (no commas or anything else)
- after 9 numbers have been entered, press the "Enter" key and enter the next numbers with the same rules

## Normal rules to solve apply:
- Each row must contain the numbers from 1 to 9, without repetitions
- Each column must contain the numbers from 1 to 9, without repetitions
- The digits can only occur once per block *(square)*
- The sum of every single row, column and block *(square)* must equal 45

### 1+2+3+4+5+6+7+8+9 = 45
