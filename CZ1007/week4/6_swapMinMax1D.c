/*
#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main()
{
    int ar[50], i, size;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d", ar+i);
    swapMinMax1D(ar, size);
    printf("swapMinMax1D(): ");
    for (i=0; i<size; i++)
        printf("%d ", *(ar+i));
    return 0;
}
void swapMinMax1D(int ar[], int size)
{
    int min, max;
    int tempMin, tempMax;
    int arMin, arMax; //i of min and max

    //findMinMax1D
    int i;

    // initialize min & max
    min = max = ar[0];

    for (i=1; i<size; i++) {
        if (ar[i] < min) {
            min = ar[i];
        }
        if (ar[i] > max) {
            max = ar[i];
        }
    }

    // prepare for swap
    for (i=size-1; i<size; i--) {
        if (ar[i] == min) {
            tempMin = ar[i];
            arMin = i;
            break;
        }
    }
    for (i=size-1; i<size; i--) {
        if (ar[i] == max) {
            tempMax = ar[i];
            arMax = i;
            break;
        }
    }

    // swapping
    ar[arMin] = tempMax;
    ar[arMax] = tempMin;

}
*/
