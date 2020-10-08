/*
#include <stdio.h>
#define SIZE 10
void transpose2D(int ar[][SIZE], int rowSize, int colSize);
void display(int ar[][SIZE], int rowSize, int colSize);
int main()
{
    int ar[SIZE][SIZE], rowSize, colSize;
    int i, j;

    printf("Enter row size of the 2D array: \n");
    scanf("%d", &rowSize);
    printf("Enter column size of the 2D array: \n");
    scanf("%d", &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for (j=0; j<colSize; j++)
            scanf("%d", &ar[i][j]);
    printf("transpose2D(): \n");
    transpose2D(ar, rowSize, colSize);
    display(ar, rowSize, colSize);
    return 0;
}
void display(int ar[][SIZE], int rowSize, int colSize)
{
    int l, m;
    for (l = 0; l < rowSize; l++) {
        for (m = 0; m < colSize; m++)
            printf("%d ", ar[l][m]);
        printf("\n");
    }
}
void transpose2D(int ar[][SIZE], int rowSize, int colSize)
{
    int l, m; // row, column
    int temp;

    for (l = 0; l < rowSize; l++) {
        for (m = 0; m < l; m++) {
        // OR for (m = l; m < colSize; m++) {
            temp = ar[l][m];
            ar[l][m] = ar[m][l];
            ar[m][l] = temp;
        }
    }
}

*/
/* ALTERNATE METHOD
{
    int l, m; // row, column
    int temp[rowSize][colSize];

    for (l = 0; l < rowSize; l++) {
        for (m = 0; m < colSize; m++) {
            temp[m][l] = ar[l][m];
        }
    }

    for (l = 0; l < rowSize; l++) {
        for (m = 0; m < colSize; m++) {
            ar[l][m] = temp[l][m];
        }
    }
}
*/

/*
[0][0] [0][1] [0][2] [0][3]
[1][0] [1][1] [1][2] [1][3]
[2][0] [2][1] [2][2] [2][3]
[3][0] [3][1] [3][2] [3][3]
*/
