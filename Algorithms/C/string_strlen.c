#include <stdio.h>
#include <string.h>
int main()
{
    char *st = "Phaham"; // strlen is used to count the numbers of characters in the string
    int a = strlen(st);  // excluding the null ('\0') character.
    printf("The length of string st is %d", a);
    return 0;
}