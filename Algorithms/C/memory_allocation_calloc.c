#include <stdio.h>
#include <stdlib.h>

int main()
{
    //     printf("The size of int on my pc is %d\n", sizeof(int));
    //     printf("The size of float on my pc is %d\n", sizeof(float));
    //     printf("The size of char on my pc is %d\n", sizeof(char));
    int *ptr;
    ptr = (int *)calloc(6, sizeof(int)); // calloc stands for continuous allocation, it initializes
    for (int i = 0; i < 6; i++)          // each memory block with a default value of 0.
    {
        printf("Enter the value of %d element: \n", i);
        scanf("%d", &ptr[i]); // if space is not sufficient, memory allocation fails and a null pointer is returned.
    }
    for (int i = 0; i < 6; i++)
    {
        printf("The value of %d element is : %d\n", i, ptr[i]);
    }

    return 0;
}