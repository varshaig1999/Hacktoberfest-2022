#include <stdio.h>
int main()
{
    FILE *ptr;

    // fgetc used to read a file character by character.

    // ptr = fopen("pk.txt", "r");
    // char c = fgetc(ptr);
    //printf("The value of my character is %c\n", c); --> to read only one character.
    // printf("The value of my character is %c\n", fgetc(ptr));
    // printf("The value of my character is %c\n", fgetc(ptr));
    // printf("The value of my character is %c\n", fgetc(ptr));
    // printf("The value of my character is %c\n", fgetc(ptr));
    // printf("The value of my character is %c\n", fgetc(ptr));
    // printf("The value of my character is %c\n", fgetc(ptr));

    // putc used for writing a file character by character. file is created automatocally.

    ptr = fopen("putcdemo.txt", "w");
    putc('P', ptr);
    putc('h', ptr);
    putc('a', ptr);
    putc('h', ptr);
    putc('a', ptr);
    putc('m', ptr);
    fclose(ptr);
    return 0;
}
