#include <iostream>
#include "headers.h"

/***************************************************************
 * This program solves a sudoku board by backtracking.
 * Used as a reference:
 * https://stackoverflow.com/questions/19022739/sudoku-solver-in-c
 *
 * @author Zachary Thomas
 * @version 1.0
 **************************************************************/
int main(int argc, char const *argv[]) {

  /** Holds the current sudoku board*/
  int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
                     { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
                     { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
                     { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                     { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                     { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                     { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                     { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
                     { 0, 7, 0, 0, 0, 0, 0, 3, 0 }};

  // Print out board before
  std::cout << std::endl << " --Board before--" << std::endl;
  toString(board);

  // Print out board after solving
  if(solve(board) == true){
    std::cout << " --Solved Board--" << std::endl;
    toString(board);
  }

  return 0;
}
