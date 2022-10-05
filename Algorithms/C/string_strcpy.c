#include <stdio.h>
#include <string.h>

int main()
{
    char *st = "This";
    char st2[45];    // strcpy function is used to copy the content of second string into first string passed to it.
    strcpy(st2, st);  // strcpy(target,source)
    printf("Now the st2 is %s", st2);
    return 0;
}