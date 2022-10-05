#include <stdio.h>

int main()
{
    FILE *ptr;
    int num;
    int num2;
    ptr = fopen("sample.txt", "r");
    fscanf(ptr, "%d", &num); // --> fscanf is a file counter part of scanf used for reading of files.
    fscanf(ptr, "%d", &num2);
    fclose(ptr); // --> close file after reading file.
    printf("The value of num is %d\n", num);
    printf("The value of num2 is %d\n", num2);
    return 0;
}