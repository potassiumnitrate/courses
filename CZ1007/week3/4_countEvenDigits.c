/*
#include <stdio.h>
int countEvenDigits1(int number);
void countEvenDigits2(int number, int *count);
int main()
{
    int number, result;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("countEvenDigits1(): %d\n", countEvenDigits1(number));
    countEvenDigits2(number, &result);
    printf("countEvenDigits2(): %d\n", result);
    return 0;
}
int countEvenDigits1(int number)
{
    int digit, count;

    count = 0;

    while (number > 0) {
        digit = number % 10;
        number /= 10;
        if (digit % 2 == 0) {
            count++;
        }
        else if (digit % 2 == 1) {
            continue;
        }
    }
    return count;
}
void countEvenDigits2(int number, int *count)
{
    int digit;

    *count = 0;

    while (number > 0) {
        digit = number % 10;
        number /= 10;
        if (digit % 2 == 0) {
            (*count)++;
        }
        else if (digit % 2 == 1) {
            continue;
        }
    }
}
*/
