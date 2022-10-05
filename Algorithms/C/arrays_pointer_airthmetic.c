#include <stdio.h>

int main()
{
    int i = 34;
    int *ptr = &i;
    printf("The value of ptr is %u\n", ptr);
    ptr++; //← it adds 4 to address if you two then it adds 8 to address and so on..
    printf("The value of ptr is %u\n", ptr);
    ptr--;                                   //← it subtracts 4 from address similar as in case of ptr++
    printf("The value of ptr is %u\n", ptr); // you can write ptr++ as ptr = ptr + 1
    return 0;
}