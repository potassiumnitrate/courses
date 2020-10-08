/*
#include <stdio.h>
float power1(float num, int p);
void power2(float num, int p, float *result);
int main()
{
    int power;
    float number, result=-1;

    printf("Enter the number and power: \n");
    scanf("%f %d", &number, &power);
    printf("power1(): %.2f\n", power1(number, power));
    power2(number,power,&result);
    printf("power2(): %.2f\n", result);
    return 0;
}
float power1(float num, int p)
{
    int count;
    float result = 1;
    while (num >= 0) {
        if (p >= 0) {
            for (count = 1; count <= p; count++) {
                result *= num;
            } break;
        }
        else if (p <= 0) {
            for (count = -1; count >= p; count--) {
                result *= (1/num);
            } break;
        }
    }
    return result;
}

void power2(float num, int p, float *result)
{
    int count;
    *result = 1;
    while (num >= 0) {
        if (p >= 0) {
            for (count = 1; count <= p; count++) {
                *result *= num;
            } break;
        }
        else if (p <= 0) {
            for (count = -1; count >= p; count--) {
                *result *= 1/num;
            } break;
        }
    }
}
*/
