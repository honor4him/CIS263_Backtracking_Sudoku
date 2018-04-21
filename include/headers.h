#ifndef __HEADERS_MAIN_
#define __HEADERS_MAIN_

/***************************************************************
 * headers.h contains all the function headers
 * for headers.cpp.
 *
 * See headers.cpp for details on what each function does.
 **************************************************************/

bool locationOpen(int board[9][9], int row, int col, int num);
bool findZero(int board[9][9], int &row, int &col);
bool solve(int board[9][9]);
void toString(int board[9][9]);
bool inRow(int board[9][9], int row, int num);
bool inCol(int board[9][9], int col, int num);
bool in3x3(int board[9][9], int sqRow, int sqCol, int num);

#endif
