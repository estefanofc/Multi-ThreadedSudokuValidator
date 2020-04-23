#include <assert.h>         // assert
#include <pthread.h>        // pthread*
#include <stdio.h>          // printf
#include <stdlib.h>         // calloc

// 'grid' holds the Sudoku grid to be checked.  Notice that we define row-0
// and column-0 to be all-zeroes.  This just makes indexing easier to
// understand: for example, the first row of the Sudoku puzzle lies
// at grid[1], elements 1 thru 9.

int grid[10][10] = {
  {0,0,0,0,0,0,0,0,0,0},
  {0,6,2,4,5,3,9,1,8,7},
  {0,5,1,9,7,2,8,6,3,4},
  {0,8,3,7,6,1,4,2,9,5},
  {0,1,4,3,8,6,5,7,2,9},
  {0,9,5,8,2,4,7,3,6,1},
  {0,7,6,2,3,9,1,4,5,8},
  {0,3,7,1,9,5,6,8,4,2},
  {0,4,9,6,1,8,2,5,7,3},
  {0,2,8,5,4,7,3,9,1,6}
};





// Check all 9 rows of the Sudoku grid, 
// using a separate thread for each row.
void checkAllRows() {
  pthread_t rowTids[10];                    // TIDs for row threads

}

// Check all 9 columns of the Sudoku grid, 
// using a separate thread for each column.
void checkAllCols() {
  pthread_t colTids[10];                    // TIDs for row threads

}

// Check all 9 boxes of the Sudoku grid, 
// using a separate thread for each box.
void checkAllBoxes() {
  pthread_t boxTids[10];                    // TIDs for row threads

}

// check rows, columns and boxes
void checkAll() {
  checkAllRows();
  checkAllCols();
  checkAllBoxes();
}


int main() {
  checkAll();
  return 0;
}