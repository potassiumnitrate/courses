/*
#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
    int data[SIZE][SIZE];
    int i,j;
    int rowSize, colSize;

    printf("Enter the array size (rowSize, colSize): \n");
    scanf("%d %d", &rowSize, &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for (j=0; j<colSize; j++)
        scanf("%d", &data[i][j]);
    printf("compress2D(): \n");
    compress2D(data, rowSize, colSize);
    return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
    int i, j; //count number of 1s or 0s
    int compare;    // capture next element in ar for comparison
    int count = 1;  // always hv at least 1 '1' or '0'
    for (i = 0; i < rowSize; i++)
    {
        compare = data[i][0];
        count = 1;

        for (j = 1; j < colSize; j++) // data[i][j] starts from 2nd element of ar
        {
            if (data[i][j] == compare) {
                count++;
            }
            else {
                printf("%d %d ", compare, count);
                compare = data[i][j]; // update compare to next element
                count = 1;
            }

        }
        printf("%d %d \n", compare, count);
    }

}

/*
4x4 matrix
[0][0] [0][1] [0][2] [0][3]
[1][0] [1][1] [1][2] [1][3]
[2][0] [2][1] [2][2] [2][3]
[3][0] [3][1] [3][2] [3][3]
*/
