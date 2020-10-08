/*
#include <stdio.h>
#define SIZE 10
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize);
int main()
{
    int ar[SIZE][SIZE], rowSize, colSize;
    int i, j, min;

    printf("Enter row size of the 2D array: \n");
    scanf("%d", &rowSize);
    printf("Enter column size of the 2D array: \n");
    scanf("%d", &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for (j=0; j<colSize; j++)
            scanf("%d", &ar[i][j]);
    min = minOfMax2D(ar, rowSize, colSize);
    printf("minOfMax2D(): %d\n", min);
    return 0;
}
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize)
{
    int i, j; //row, column

    int max = ar[0][0]; // max of each row

    int minOfMax = ar[0][0];

    for (i=0; i<rowSize; i++) {
        for (j=0; j<colSize; j++) {
            if (ar[i][j] > max) {
                max = ar[i][j];
            }
        }

        /* for ar[0][j]: comparing ar[0][0] to max
           e.g. minOfMax = ar[0][0] = 0, max = 4;
                max is more than minOfMax (WRONG)
        *//*
        // therefore need i==0 as it is an exception ^
        if (i == 0) {
            minOfMax = max;
        }
        else if (max < minOfMax)
        {
            minOfMax = max;
        }
        max = 0;
    }

    return minOfMax;
}
*/
