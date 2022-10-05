// Does ptr = ptr + 2 and ptr == &arr[2] points to same location?
#include <stdio.h>

int main()
{
    int arr[10]; //if s[3] isa 1-d array of integers then *(s+3) refers to 2nd
    // int *ptr = &arr[0];          element because index starts with 0.
    int *ptr = arr;
    ptr = ptr + 2;
    if (ptr == &arr[2])
    {
        printf("These values point to the same location in memeory\n");
    }
    else
    {
        printf("These values do not point to the same location in memeory");
    }
    return 0;
}