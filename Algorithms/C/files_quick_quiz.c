// Modify the program file_reading.c to check whether the file exists or not before opening the file.
#include <stdio.h>

int main()
{
    FILE *ptr;
    int num;
    int num2;
    ptr = fopen("samplle.txt", "r");
    if (ptr == NULL)
    {
        printf("This file doesn't exist");
    }
    else
    {
        fscanf(ptr, "%d", &num); // --> fscanf is a file counter part of scanf.
        fscanf(ptr, "%d", &num2);
        fclose(ptr); // --> close file after reading file.
        printf("The value of num is %d\n", num);
        printf("The value of num2 is %d\n", num2);
    }
    return 0;
}