/*
#include <stdio.h>
void rReverseAr(int ar[], int size);
int main()
{
    int array[80];
    int size, i;

    printf("Enter size: \n");
    scanf("%d", &size);
    printf("Enter %d numbers: \n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);
    printf("rReverseAr(): ");
    rReverseAr(array, size);
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
void rReverseAr(int ar[], int size)
{
    int temp, i = 0;

    if (size == 1) {
        return;
    }
    else {
        if (i<size-1) {
            temp = ar[i];
            ar[i] = ar[size-1];
            ar[size-1] = temp;
        }

        rReverseAr(ar+1, size-2);
    }
}
*/
