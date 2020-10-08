/*
#include <stdio.h>
#include <string.h>
int countWords(char *s);
int main()
{
    char str[50], *p;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str,'\n')) *p = '\0';
    printf("countWords(): %d", countWords(str));
    return 0;
}
int countWords(char *s)
{
    int i = 0; // index

    // 1 bc it only increments at the next space
    int noOfWords = 1;

    int len;
    len = strlen(s);

    while (i <= len) {
        if (s[i] == ' ') {
            noOfWords++;
            i++;
            continue;
        }
        i++;
    }
    return noOfWords;
}
*/
