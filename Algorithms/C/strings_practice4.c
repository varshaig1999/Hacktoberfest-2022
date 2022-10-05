// Write a function slice() to slice a string. It should change the original string such that it is now
// the sliced string. Take m and n asm  the starting and ending position for slice.
#include <stdio.h>
void slice(char *st, int m, int n)
{
    int i = 0;
    while ((m + i) < n)
    {
        st[i] = st[i + m];
        i++;
    }
    st[i] = '\0';
}

int main()
{
    char st[] = "Phaham";
    slice(st, 1, 5);
    printf("%s", st);
    return 0;
}