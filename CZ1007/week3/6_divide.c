/*
#include <stdio.h>
int divide1(int m, int n, int *r);
void divide2(int m, int n, int *q, int *r);
int main()
{
    int m, n, q, r;

    printf("Enter two numbers (m and n): \n");
    scanf("%d %d", &m, &n);
    q = divide1(m, n, &r);
    printf("divide1(): quotient %d remainder %d\n", q, r);
    divide2(m, n, &q, &r);
    printf("divide2(): quotient %d remainder %d\n", q, r);
    return 0;
}
int divide1(int m, int n, int *r)
{
    int q;

    q = 0;

    if (m >= n) {
        while (m - q * n > n) {
            if (m - q * n > 0) {
                q++;
            }
            *r = m - q * n;
        }
    }
    else if (m < n) {
        q = 0;
        *r = m;
    }
    return q;
}
void divide2(int m, int n, int *q, int *r)
{
    *q = 0;
    if (m >= n) {
        while (m - *q * n > n) {
            if (m - *q * n > 0){
                (*q)++;
            }
            *r = m - *q * n;
        }
    }
    else if (m < n) {
        *q = 0;
        *r = m;
    }
}
*/
