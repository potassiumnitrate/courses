/*
#include <stdio.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
    extEvenDigits2(number, &result);
    printf("extEvenDigits2(): %d\n", result);
    return 0;
}
int extEvenDigits1(int num)
{
    int digit, result = 0, x = 1;
    int odd = 0, intSize = 0;
    while (num > 0) {
        digit = num % 10;
        num /= 10;
        intSize++;
        if (digit % 2 == 0) {
            result += digit*x;
            x *= 10;
        }
        else {
            odd++;
            continue;
        }
    }
    if (odd == intSize) {
        result = -1;
    }
    return result;
}
void extEvenDigits2(int num, int *result)
{
    int digit, x = 1;         //x is the 1,10th etc position of the digit
    int odd = 0, intSize = 0;
    *result = 0;
    while (num > 0) {
        digit = num % 10;
        num /= 10;
        intSize++;
        if (digit % 2 == 0) {
            *result += digit*x;
            x *= 10;
        }
        else {
            odd++;
            continue;
        }
    }
    if (odd == intSize) {
        *result = -1;
    }
}
*/
