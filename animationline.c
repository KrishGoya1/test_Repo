#include <stdio.h>
#include <time.h>

int main() {
    int i;
    int animationWidth = 300;  // Width of the animation
    int linePosition = 2;    // Initial position of the line

    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 200000000;  // 200 milliseconds

    for (i = 0; i < animationWidth; i++) {
        // Clear the screen
        printf("\033[2J");
        
        // Print spaces to position the line
        for (int j = 0; j < linePosition; j++) {
            printf(" ");
        }

        // Print the line
        printf("*\n");

        // Update the line position
        linePosition++;

        // Add a delay between frames
        nanosleep(&delay, NULL);
    }

    return 0;
}