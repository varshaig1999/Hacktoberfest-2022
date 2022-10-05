#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, nguesses = 1;
    srand(time(0));
    num = rand() % 100 + 1;
    //printf("The number is %d\n", num);
    do
    {
        printf("Guess the number between 1 to 100\n");
        scanf("%d", &guess);
        if (guess > num)
        {
            printf("Lower number please\n");
        }
        else if (guess < num)
        {
            printf("Higher number please\n", nguesses);
        }
        else
        {
            printf("You guessed in %d attempts", nguesses);
        }
        nguesses++;
    } while (guess != num);

    return 0;
}