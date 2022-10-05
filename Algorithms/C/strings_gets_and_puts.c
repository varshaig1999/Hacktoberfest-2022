#include <stdio.h>

int main()
{
    char s[25];
    printf("Enter your name: "); //gets is a functionwhich can be used to receive a multi-word string.
    gets(s);                     // For Ex- If you have to print name including spaces then use gets instead of scanf.
    puts(s);                     // puts print the string andnplace cursor o new line.
    printf("Your name is %s", s);
    return 0;
}