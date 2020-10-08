
#include <stdio.h>
#include <string.h>
#define INIT_VALUE -1
int countSubstring(char str[], char substr[]);
int main()
{
    char str[80], substr[80], *p;
    int result = INIT_VALUE;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str,'\n')) *p = '\0';
    printf("Enter the substring: \n");
    fgets(substr, 80, stdin);
    if (p=strchr(substr,'\n')) *p = '\0';
    result = countSubstring(str, substr);
    printf("countSubstring(): %d\n", result);
    return 0;
}
int countSubstring(char str[], char substr[])
{
    int i=0, j=0;

    int count = 0;

    int lenStr = strlen(str);
    int lenSubstr = strlen(substr);

    for (i=0; i<=(lenStr - lenSubstr); i++) {
        for (j=i; j<(i+lenSubstr); j++) {
            if (str[j] != substr[j-i]) {
                break;
            }
            else if (str[j] == substr[j-i]) {
                if (str[j + lenSubstr - 1] == substr[lenSubstr - 1]) {
                    count++;
                    i++;
                }
                else {
                    continue;
                }
            }
        }
    }
    return count;
}

