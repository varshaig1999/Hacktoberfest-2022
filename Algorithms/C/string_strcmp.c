#include <stdio.h>
#include <string.h>

int main()
{
    char st1[45] = "Hello";
    char *st2 = "Phaham";             // strcmp function is used to compare two strings.
    int val = strcmp(st1, st2);       // it returns 0 if strings are equal.
    printf("Now the st1 is %d", val); // negative value if first string'smismatching character's ASCII
    return 0;                         // value is not greater than  second string's corresponding
} // mismatching character. It returns positive values otherwise.