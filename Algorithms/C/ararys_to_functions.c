#include <stdio.h>

// void printArray(int *ptr, int n)
void printArray(int ptr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // printf("The value of element %d is %d\n", i + 1, *(ptr + i));
        printf("The value of element %d is %d\n", i + 1, ptr[i]);
    
    // ptr[2] = 5; →→→→→→→→→→→→→→→→→→→→→→→→→→
} //                       ↓
int main()                             //  ↓
{                                      //    ↓
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; //  ↓
    printArray(arr, 7);                //   ↓
    // printf("%d", arr[2]);  ←←←←←←←←←←←←←←←
    return 0;
}