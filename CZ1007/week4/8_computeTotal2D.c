/*
#include <stdio.h>
#define SIZE 4
void computeTotal2D(int matrix[SIZE][SIZE]);
int main()
{
    int a[SIZE][SIZE];
    int i, j;
    printf("Enter the matrix data (%dx%d): \n", SIZE, SIZE);
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
            scanf("%d", &a[i][j]);
    printf("computeTotal2D(): \n");
    computeTotal2D(a);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
void computeTotal2D(int matrix[SIZE][SIZE])
{
    int i, j; //row, column
    int sum = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j < 3) {
                sum += matrix[i][j];
            }
            if (j == 3) {
                matrix[i][j] = sum;
            }
        }
        sum = 0;
    }
}
*/
