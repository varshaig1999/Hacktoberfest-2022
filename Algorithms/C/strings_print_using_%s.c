#include <stdio.h>

int main()
{
    char *ptr = "Phaham";
    // char ptr[] = "Phaham";        This is another way,   Once a string is defined using char st[] = "Phaham" it can't be reinitialised to something else.
    printf("%s", ptr);
    return 0;
}