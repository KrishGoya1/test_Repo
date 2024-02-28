// Implement a program that copies the contents of one file into another file, character by character.

#include<stdio.h>
#include<stdlib.h>

int main(){
    char file1[200];
    printf("Enter the file path and name : ");
    scanf("%s",&file1);

    FILE* ptr1 = fopen(file1,"r");
    if(ptr1 == NULL){
        printf("Error opening the file");
        return 0;
    }
    char copiedfilename[40];
    snprintf(copiedfilename, sizeof(copiedfilename), "copy of %s", file1);
    FILE* ptr2 = fopen(copiedfilename,"w");
    if(ptr2 == NULL){
        printf("error creating the copy");
        return 0;
    }
    char c;
    while((c=fgetc(ptr1))!=EOF){
        fputc(c,ptr2);
    }
    
    fclose(ptr2);
    fclose(ptr1);

    return 0;
}