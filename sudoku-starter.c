#include <assert.h>         // assert
#include <pthread.h>        // pthread*
#include <stdio.h>          // printf
#include <stdlib.h>         // calloc

// 'grid' holds the Sudoku grid to be checked.  Notice that we define row-0
// and column-0 to be all-zeroes.  This just makes indexing easier to
// understand: for example, the first row of the Sudoku puzzle lies
// at grid[1], elements 1 thru 9.

int grid[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 6, 2, 4, 5, 3, 9, 1, 8, 7},
    {0, 5, 1, 9, 7, 2, 8, 6, 3, 4},
    {0, 8, 3, 7, 6, 1, 4, 2, 9, 5},
    {0, 1, 4, 3, 8, 6, 5, 7, 2, 9},
    {0, 9, 5, 8, 2, 4, 7, 3, 6, 1},
    {0, 7, 6, 2, 3, 9, 1, 4, 5, 8},
    {0, 3, 7, 1, 9, 5, 6, 8, 4, 2},
    {0, 4, 9, 6, 1, 8, 2, 5, 7, 3},
    {0, 2, 8, 5, 4, 7, 3, 9, 1, 6}
};

/* structure for passing data to threads */
typedef struct {
  int row;
  int column;
} parameters;

void *checkRow(void *arg) {
  parameters *param = (parameters*) arg;
  int row = param->row;
  int col = param->column;
  int countArr[9] = {0};
  for (int i = 1; i < 10; ++i) {
    int curr = grid[row][i];
    if(curr < 1 || curr > 9 || countArr[curr - 1] == 1) {
      pthread_exit(NULL);
    } else {
      countArr[curr - 1] = 1;
    }
  }
}

// Check all 9 rows of the Sudoku grid,
// using a separate thread for each row.
void checkAllRows() {
  pthread_t rowTids[10];                    // TIDs for row threads


}

void *checkColumn(void *arg) {
  parameters *param = (parameters*) arg;
  int row = param->row;
  int col = param->column;
  int countArr[9] = {0};
  for (int i = 1; i < 10; ++i) {
    int curr = grid[i][col];
    if(curr < 1 || curr > 9 || countArr[curr - 1] == 1) {
      pthread_exit(NULL);
    } else {
      countArr[curr - 1] = 1;
    }
  }
}

// Check all 9 columns of the Sudoku grid, 
// using a separate thread for each column.
void checkAllCols() {
  pthread_t colTids[10];                    // TIDs for row threads

}

void* checkBox(void* arg) {
  parameters *param = (parameters*) arg;
  int row = param->row;
  int col = param->column;
  int countArr[9] = {0};
  for (int i = row; i < row + 3; i++) {
    for (int j = col; j < col + 3; j++) {
      int curr = sudoku[i][j];
      if (curr < 1 || curr > 9 || countArr[curr - 1] == 1) {
        pthread_exit(NULL);
      } else {
        countArr[curr - 1] = 1;
      }
    }
  }
  // If reached this point, 3x3 subsection is valid.
  //valid[row + col/3] = 1; // Maps the subsection to an index in the first 8
  // indices of the valid array
  pthread_exit(NULL);
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