#include <iostream>
#include "headers.h"

/***************************************************************
 * headers.cpp contains all the function code from the headers
 * in headers.h.
 **************************************************************/

/***************************************************************
* This function solves the sudoku board by backtracking.
* @param int board Sudoku board
* @return bool If true, finsiehd, if not, continue.
**************************************************************/
bool solve(int board[9][9])
{
    /** Holds the current row*/
    int row;

    /** Holds the current column*/
    int col;

    // Find next zero to replace
    if (!findZero(board, row, col))
       return true;

    // Check and see what number to insert
    for (int insert = 1; insert <= 9; insert++)
    {
        if (locationOpen(board, row, col, insert))
        {
            // Insert number
            board[row][col] = insert;

            // Recursive backtracking call, finished if true.
            if (solve(board))
                return true;

            // Remove number if can't be placed
            board[row][col] = 0;
        }
    }
    // Continue when false
    return false;
}

/***************************************************************
* This function finds a zero in the sudoku board.
* @param int board Sudoku board
* @param int &row reference to row
* @param int &col reference to column
* @return bool If true, found. If not, no more zeros
**************************************************************/
bool findZero(int board[9][9], int &row, int &col)
{
    // Nested for loop to find zero
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (board[row][col] == 0)
                return true;
    return false;
}

/***************************************************************
* This function sees if the current number to insert is in the
* current row of the sudoku board.
* @param int board Sudoku board
* @param int row Current row
* @param int col Current column
* @return bool If true, found. If not, can insert.
**************************************************************/
bool inRow(int board[9][9], int row, int insert)
{
    for (int col = 0; col < 9; col++)
        if (board[row][col] == insert)
            return true;
    return false;
}

/***************************************************************
* This function sees if the current number to insert is in the
* current column of the sudoku board.
* @param int board Sudoku board
* @param int row Current row
* @param int col Current column
* @return bool If true, found. If not, can insert.
**************************************************************/
bool inCol(int board[9][9], int col, int insert)
{
    for (int row = 0; row < 9; row++)
        if (board[row][col] == insert)
            return true;
    return false;
}

/***************************************************************
* This function sees if the current number to insert is in the
* current 3 x 3 square of the sudoku board.
* @param int board Sudoku board
* @param int sqRow Current row in square
* @param int sqCol Current column in square
* @param int insert Number to insert
* @return bool If true, found. If not, can insert.
**************************************************************/
bool in3x3(int board[9][9], int sqRow, int sqCol, int insert)
{
    // Nested for loop to go over square
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board[row + sqRow - sqRow % 3]
                     [col + sqCol - sqCol % 3] == insert)
                return true;
    return false;
}

/***************************************************************
* This function sees if the current number to insert is in the
* current column, row, or current square of the board.
* @param int board Sudoku board
* @param int row Current row
* @param int col Current column
* @param int insert Number to insert
* @return bool If true, found. If not, can insert.
**************************************************************/
bool locationOpen(int board[9][9], int row, int col, int insert)
{
  // Only return true if not in row, col or current square
  return !inRow(board, row, insert) &&
         !inCol(board, col, insert) &&
         !in3x3(board, row , col, insert);
}

/***************************************************************
* This function prints the board to the screen.
* @param int board Sudoku board
**************************************************************/
void toString(int board[9][9]){
  for (int row = 0; row < 9; row++)
  {
     for (int col = 0; col < 9; col++)
           std::cout << board[row][col] << " ";

      std::cout << std::endl;
  }
  std::cout << std::endl;
}
