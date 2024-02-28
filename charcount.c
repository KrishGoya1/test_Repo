#include<stdio.h>
#include<ctype.h>

int main(){
    char filename[30];
    printf("enter the file path and name : ");
    scanf("%s",&filename);

    FILE* ptr = fopen(filename,"r");
    if(ptr == NULL)
        exit(printf("error"));

        char c;
        int character = 0;
        int words = 0;

        while((c = fgetc(ptr)) != EOF){
            if(c == ' '){
                words++;
            }else{
                character++;
            }
        }

    printf("\nthe number of characters = %d",character);
    printf("\nthe number of words = %d",words+1);

    fclose(ptr);
    return 0;
}