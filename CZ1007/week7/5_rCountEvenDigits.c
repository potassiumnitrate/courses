/*
#include <stdio.h>
int rCountEvenDigits1(int num);
void rCountEvenDigits2(int num, int *result);
int main()
{
    int number, result;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("rCountEvenDigits1(): %d\n", rCountEvenDigits1(number));
    rCountEvenDigits2(number, &result);
    printf("rCountEvenDigits2(): %d\n", result);
    return 0;
}
int rCountEvenDigits1(int num)
{

    int digit = 0;

    if (num <= 0) {
        return 0;
    }

    else {
        digit = num % 10;

        if (digit % 2 == 0) {
            return 1 + rCountEvenDigits1(num/10);
        }
        if (digit % 2 != 0) {
            return rCountEvenDigits1(num/10);
        }
    }

}
void rCountEvenDigits2(int num, int *result)
{

    int digit = 0;

    if (num <= 0) {
        *result = 0;
    }

    else {
        digit = num % 10;

        if (digit % 2 == 0) {
        rCountEvenDigits2(num/10, result);
        *result += 1;
        }
        if (digit % 2 != 0) {
        rCountEvenDigits2(num/10, result);
        }
    }

}
*/
