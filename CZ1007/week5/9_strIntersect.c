/*
#include <stdio.h>
void strIntersect(char *str1, char *str2, char *str3);
int main()
{
    char str1[50], str2[50], str3[50];

    printf("Enter str1: \n");
    scanf("%s", str1);
    printf("Enter str2: \n");
    scanf("%s", str2);
    strIntersect(str1, str2, str3);
    if (*str3 == '\0')
        printf("strIntersect(): null string\n");
    else
        printf("strIntersect(): %s\n", str3);
    return 0;
}
void strIntersect(char *str1, char *str2, char *str3)
{
    int i=0, j=0, k=0;
    int len1=0, len2=0;

    str3[k] = '\0';

    while ((str1[i] >= 'A' && str1[i] <= 'Z') ||
           (str1[i] >= 'a' && str1[i] <= 'z') ||
           (str1[i] >= '0' && str1[i] <= '9') ) {
        len1++;
        i++;
    }
    while ((str2[j] >= 'A' && str2[j] <= 'Z') ||
           (str2[j] >= 'a' && str2[j] <= 'z') ||
           (str2[j] >= '0' && str2[j] <= '9') ) {
        len2++;
        j++;
    }

    for (i=0; i<len1; i++) {
        for (j=0; j<len2; j++) {
            if (str2[j] == str1[i]) {
                str3[k] = str2[j];
                k++;
            }
            else {
                continue;
            }
        }
    }

}
*/
