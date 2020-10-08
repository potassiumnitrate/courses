/*
#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main()
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str,'\n')) *p = '\0';
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}
void maxCharToFront(char *str)
{
    int i, j; //index, index
    char maxChar = 'a';

    for (i=0; i<strlen(str); i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if ( str[i] > maxChar ) {
                maxChar = str[i];
            }
        }
    }

    char *ptr = strchr(str, maxChar);

    i = ptr - str;

    for (j=i; j>0; j--) {
        str[j] = str[j-1];
    }

    str[0] = maxChar;
}
*/
