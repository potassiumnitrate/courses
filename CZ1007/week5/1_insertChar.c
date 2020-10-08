/*
#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
    char a[80], b[80];
    char ch, *p;

    printf("Enter a string: \n");
    fgets(a, 80, stdin);
    if (p=strchr(a,'\n')) *p = '\0';
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a,b,ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
    int i=0, j=0; //str1[i], str2[j]
    int len1, len2;

    len1 = strlen(str1);
    len2 = strlen(str1) + strlen(str1) / 3;

    while (i <= len1 && j <= len2) {
        if ((j+1) % 4 == 0) {
            str2[j] = ch;
        }
        else {
            str2[j] = str1[i];
            i++;
        }
        j++;
    }
    if ((j+1) % 4 == 0) {
        str2[j] = ch;
    }
}
*/
