// Write your own version of strcpy function fron <string.h>
#include <stdio.h>
#include <string.h>
int strcpy(char *st)
{
    char *ptr = st;
}

int main()
{
    char st[] = "Phaham";
    char st2[25];
    int l = strcpy(st2, st);
    printf("Now the st2 is %s\n", st2);
    return 0;
}