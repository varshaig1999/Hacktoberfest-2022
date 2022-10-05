// Write a program to decrypt the string by encrypted using encrypt function in problem 6.
#include <stdio.h>
void decrypt(char *c)
{
    char *ptr = c;
    while (*ptr != '\0')
    {
        *ptr = *ptr - 1;
        ptr++;
    }
}
int main()
{
    char c[] = "Qibibn ";
    decrypt(c);
    printf("Decrypted string is: %s\n", c);
    return 0;
}