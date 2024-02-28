#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int wordCount = 0;
    int inWord = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    //Open the file in read mode JAJAJA
    file = fopen(filename, "r");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Check if the character is an alphabet or an apostrophe
        if (isalpha(ch) || ch == '\'') {
            inWord = 1;
        }
        // If the character is not an alphabet or an apostrophe, and we were previously in a word, increment the word count
        else if (inWord) {
            wordCount++;
            inWord = 0;
        }
    }

    // Check if the last word in the file is not followed by any non-alphabetic character
    if (inWord) {
        wordCount++;
    }

    // Close the file
    fclose(file);

    printf("Number of words in the file: %d\n", wordCount);

    return 0;
} 