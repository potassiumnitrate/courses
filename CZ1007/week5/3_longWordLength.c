/*
#include <stdio.h>
#include <string.h>
int longWordlength(char *s);
int main()
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str, '\n')) *p = '\0';
    printf("longWordLength(): %d\n", longWordlength(str));
    return 0;
}
int longWordlength(char *s)
{
    int i, longest = 0;
    int lengthsubS = 0; //length of 1 word

    for (i=0; i<strlen(s); i++) {
        if ( !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ) {
            lengthsubS = 0;
            continue;
        }
        lengthsubS++;

        if (lengthsubS >= longest) {
            longest = lengthsubS;
        }
        if (s[i] == '\0' || s[i] == ' ') {
            lengthsubS = 0; //reset to 0
            continue;
        }

    }
    return longest;
}
// !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
*/
