#include <stdio.h>
#include <string.h>

int main()
{
    char st1[45] = "Hello";
    char *st2 = "Phaham";
    strcat(st1, st2); // strcat function is used to concatenate two strings.
    printf("Now the st1 is %s", st1);
    return 0;
}