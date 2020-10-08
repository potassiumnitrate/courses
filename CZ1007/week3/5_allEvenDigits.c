/*
#include <stdio.h>
int allEvenDigits1(int num);
void allEvenDigits2(int num, int *result);
int main()
{
    int number, p=999, result=999;

    printf("Enter a number: \n");
    scanf("%d", &number);
    p = allEvenDigits1(number);
    if (p == 1)
        printf("allEvenDigits1(): yes\n");
    else if (p == 0)
        printf("allEvenDigits1(): no\n");
    else
        printf("allEvenDigits1(): error\n");
    allEvenDigits2(number, &result);
    if (result == 1)
        printf("allEvenDigits2(): yes\n");
    else if (result == 0)
        printf("allEvenDigits2(): no\n");
    else
        printf("allEvenDigits2(): error\n");
    return 0;
}
int allEvenDigits1(int num)
{
    int digit, result = 0;       // result is for whether single digit is even
    while (num > 0) {
        digit = num % 10;
        num /= 10;
        if (digit % 2 == 0) {
            result += 1;
        }
        else if (digit % 2 == 1) {
            result += 0;
            break;
        break;
        }
    }
    if (result >= 1) {
        return 1;
    }
    else {
        return 0;
    }
}
void allEvenDigits2(int num, int *result)
{
    int digit;
    *result = 0;
    while (num > 0) {
        digit = num % 10;
        num /= 10;
        if (digit % 2 == 0) {
            *result += 1;
        }
        else if (digit % 2 == 1) {
            *result = 0;
            break;
        break;
        }
    }
    if (*result >= 1) {
        *result = 1;
    }
    else {
        *result = 0;
    }
}
*/
