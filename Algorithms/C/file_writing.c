#include <stdio.h>

int main()
{
    FILE *fptr; //--> you can give names according to your choice it may be ptr, fptr or p.
    int num = 45;
    fptr = fopen("generated.txt", "w");     //--> file with the name generated.txt will be automatically created.
    fprintf(fptr, "The number is %d", num); //--> fprintf used for writing of files.
    fclose(fptr);

    return 0;
}