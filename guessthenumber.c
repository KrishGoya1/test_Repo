#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int a, guess, lives = 5;
    printf("\n\033[1m\033[34m\t\t##### GUESS THE NUMBER #####\033[0m\n");
    srand(time(NULL));
    a = rand() % 100;
    
    printf("\n\033[33m\t\thint : The number is between 0 and 100 ;)\033[0m\n");

    // printf("\n\t\tCHEATING FOR TESTING PURPOSE : num=%d",a);

    do {
        printf("\n\033[36m\t\t\t\t\t\t%d lives remaining\033[0m\n", lives);
        printf("\033[37mEnter Your guess : \033[0m");
        scanf("%d", &guess);
        lives--;

        if (guess < a) {
            printf("\n\033[31mToo Low\033[0m\n");
        } else if (guess > a) {
            printf("\n\033[31mToo High\033[0m\n");
        } else {
            printf("\n\033[32m\033[1m\t\tCONGRATULATIONS! YOU GOT THE ANSWER\033[0m\n");
        }
    } while (guess != a && lives);

    if (!lives) {
        printf("\n\033[31m\t0 lives remaining :(\n");
        printf("\tThe number was %d\n\033[m", a);
    }

    return 0;
}