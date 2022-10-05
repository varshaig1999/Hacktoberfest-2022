// Write a program containing a function which reverses the array passed to it?
#include <stdio.h>
void reverse(int *arr, int n)
{
    int temp;
    for (int i = 0; i < (n / 2); i++) // you may put 3 at place of n/2, we are reversing until 3
    {                                 // because if we go further the values agin reversed means
        temp = arr[i];                // they are in again same as apassed values.
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp; //index starts from 0mmeans 1 at i=0, 2 at i=1 and so on....
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    reverse(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("The value of %d element is: %d\n", i, arr[i]);
    }

    return 0;
}