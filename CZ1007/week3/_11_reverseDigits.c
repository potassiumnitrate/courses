
#include <stdio.h>
int reverseDigits1(int num);
void reverseDigits2(int num, int *result);
int main()
{
    int num, result=999;

    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits1(): %d\n", reverseDigits1(num));
    reverseDigits2(num, &result);
    printf("reverseDigits2(): %d\n", result);
    return 0;
}
int reverseDigits1(int num)
{
    int digit, result = 0, numSize = 0;

    while (num > 0) {
        digit = num % 10;
        num /= 10;
        result = (result * 10) + digit;
        numSize++;
    }

    return result;
}
void reverseDigits2(int num, int *result)
{
    int digit, numSize = 0;

    *result = 0;

    while (num > 0) {
        digit = num % 10;
        num /= 10;
        *result = ((*result) * 10) + digit;
        numSize++;
    }

}
