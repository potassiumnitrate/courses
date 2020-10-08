/*
#include <stdio.h>
int perfectProd1(int num);
void perfectProd2(int num, int *prod);
int main()
{
    int number, result=0;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("Calling perfectProd1() \n");
    printf("perfectProd1(): %d\n", perfectProd1(number));

    printf("Calling perfectProd2() \n");
    perfectProd2(number, &result);
    printf("perfectProd2(): %d\n", result);
    return 0;
}
int perfectProd1(int num)
{
    int i, j;
    int sum;
    int prod = 1;

    //start loop until max
    for (i=1; i<num; i++) {

        sum = 0;

        //find factor of num
        for (j=1; j<i; j++) {
            int k = i % j;
            if (k == 0) {
                //factor found, add into sum
                sum += j;
            }
        }

        //after get sum of factors, check if it is a perfect factor
        if (sum == i) {
            printf("Perfect number: %d \n", i);
            prod *= sum;
        }
    }

    return prod;
}
void perfectProd2(int num, int *prod)
{
    int i, j;
    int sum;

    *prod = 1;

    //start loop until max
    for (i=1; i<num; i++) {

        sum = 0;

        //find factor of num
        for (j=1; j<i; j++) {
            int k = i % j;
            if (k == 0) {
                //factor found, add into sum
                sum += j;
            }
        }
        //after get sum of factors, check if it is a perfect factor
        if (sum == i) {
            printf("Perfect number: %d \n", i);
            (*prod) *= sum;
        }
    }
}
*/
