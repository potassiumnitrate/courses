/*
// gcd - greatest common divisor
#include <stdio.h>
int gcd1(int num1, int num2);
void gcd2(int num1, int num2, int *result);
int main()
{
    int x,y,result=-1;

    printf("Enter 2 numbers: \n");
    scanf("%d %d", &x, &y);
    printf("gcd1(): %d\n", gcd1(x, y));
    gcd2(x,y,&result);
    printf("gcd2(): %d\n", result);
    return 0;
}
int gcd1(int num1, int num2)
{
    int div; //divisor
    int result;

    for (div = 1; div <= num1 && div <= num2; div++) {
        if (num1 % div == 0 && num2 % div == 0) {
            result = div;
        }
    }

    return result;
}
void gcd2(int num1, int num2, int *result)
{
    int div; //divisor

    *result = 0;

    for (div = 1; div <= num1 && div <= num2; div++) {
        if (num1 % div == 0 && num2 % div == 0) {
            *result = div;
        }
    }

}
*/
