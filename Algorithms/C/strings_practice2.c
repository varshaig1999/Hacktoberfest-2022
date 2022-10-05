// Write a progtam to take string as an input from the user using %c and %s. Confirm that strings
// are equal.
#include <stdio.h>
#include <string.h>

int main()
{
    char st1[34];
    char st2[34];
    char c;
    int i = 0;
    printf("Enter the value of first string\n");
    scanf("%s", st1);
    printf("Enter the value of second string character by character\n");
    while (c != '\n')
    {
        fflush(stdin); //fflush flushes values of previous scanf.
        scanf("%c", &c);
        st2[i] = c;
        i++;
    }
    st2[i - 1] = '\0'; // to exclude \n extra character added.
    printf("The value of st1 is %s\n", st1);
    printf("The value of st2 is %s\n", st2);
    printf("strcmp for these strings returns %d\n", strcmp(st1, st2));

    return 0;
}