// Write a program to check whether a given character is present in a string or not.
#include <stdio.h>
int presence(char st[], char c)
{
    char *ptr = st;
    int strchr = 0;
    while (*ptr != '\0')
    {
        if (*ptr == c)
        {
            strchr++;
        }
        ptr++;
    }
    return strchr;
}
int main()
{
    char st[] = "Phaham";
    int strchr = presence(st, 'k');
    printf("presence = %d", strchr);
    return 0;
}