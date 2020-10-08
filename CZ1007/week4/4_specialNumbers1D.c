/*
#include <stdio.h>
void specialNumbers1D(int ar[], int num, int *size);
int main()
{
    int a[20],i,size=0,num;

    printf("Enter a number (between 100 and 999): \n");
    scanf("%d", &num);
    specialNumbers1D(a, num, &size);
    printf("specialNumbers1D(): ");
    for (i=0; i<size; i++)
        printf("%d ",a[i]);
    return 0;
}
void specialNumbers1D(int ar[], int num, int *size)
{
    int test_num, ones, tenths, hundredths;
    int specNum=0;

    int index_array = 0;

    for (test_num = 100; test_num < num; test_num++) {

        // mod 10 then divide by 10 to get every digit value
        int manipulate_num = test_num;
        ones = manipulate_num % 10;
        manipulate_num /= 10;
        tenths = manipulate_num % 10;
        manipulate_num /= 10;
        hundredths = manipulate_num % 10;

        specNum = (hundredths*hundredths*hundredths) + (tenths*tenths*tenths) + (ones*ones*ones);

        // compare w test_num & not num, which is the final value
        if (specNum == test_num)
        {
            ar[index_array] = specNum;
            index_array++;

        }
        // reset specNum for each iteration
        specNum = 0;
        }
         //to tell the main program how many numbers need to print out
        *size = index_array;
}
*/
