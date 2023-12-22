#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr [])
{

    // This is the first programming (scripting) question without any initial setup as hints.

    // This is also the first question requiring you to come up with an algorithm on paper 
    // with mathematical analysis before implementing the code.
    /*int index = 0, rows = 0, cols = 0;

    for(int i = 0; i < N3; i++){


        if(i>=4){
            rows = i-3;
            cols = 3;
        } else {
            cols = i;
        }

        while(rows <= 3){
            arr[index] = mat[rows][cols];
            cols--;
            rows++;
            index++;
        }

    // High Level Hint:
    //  Assume a 3x3 square matrix, look at the SUM of the row and column indices of each element.
    //  You should be able to see a numerical pattern after doing so.

}
*/
    int index = 0;

    //loop for 00,01,10,02,11,20
    for(int i = 0; i < N3; i++){
        int startCol = i, startRow = 0;

        while (startCol>= 0 && startRow < N3) { 
            arr[index++] = mat[startRow][startCol];
            startCol--;
            startRow++;
        }
    }


    //loop for 12, 21, 22
    for(int r = 1; r < N3; r++) {
        int startRow = r, startCol = N3-1;

        while (startRow < N3 && startCol >= 0) {
            arr[index++] = mat[startRow][startCol];
            startCol--;
            startRow++;
        }
    }
}