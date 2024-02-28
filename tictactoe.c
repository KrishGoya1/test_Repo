#include<stdio.h>
#include<stdbool.h>

#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA     "\x1b[35m"
#define CYAN        "\x1b[36m"
#define RESET       "\x1b[0m"
#define BOLD        "\x1b[1m"
#define DULL        "\x1b[2m"
#define ITALIC      "\x1b[3m"
#define UNDERLINED  "\x1b[4m"
#define HIGHLIGHTED "\x1b[7m"

#define BGblack      "\x1b[40m"
#define BGred        "\x1b[41m"
#define BGgreen      "\x1b[42m"
#define BGyellow     "\x1b[43m"
#define BGblue       "\x1b[44m"
#define BGmagenta    "\x1b[45m"
#define BGcyan       "\x1b[46m"
#define BGwhite      "\x1b[47m"
char b[]={'0','1','2','3','4','5','6','7','8','9'};
void printBoard(int x,bool plyr){
    b[x]=plyr?'O':'X';
printf("%s%s\n\n",BGblack,BOLD);
    printf("\t\t\t\t\t%c\t|\t%c\t|\t%c\n",b[7],b[8],b[9]);
    printf("\t\t\t\t________________|_______________|________________\n");
    printf("\t\t\t\t\t%c\t|\t%c\t|\t%c\n",b[4],b[5],b[6]);
    printf("\t\t\t\t________________|_______________|________________\n");
    printf("\t\t\t\t\t%c\t|\t%c\t|\t%c\n",b[1],b[2],b[3]);
printf("%s",RESET);
}

int main(){
    int a=0,movesPlayed=0;
    bool player=1;
    printf("%s%s\t\t\t\tW E L C O M E  T O  T I C - T A C - T O E%s\n\n",BOLD,YELLOW,RESET);
    printBoard(a,player);
    printf("\n\t\t\t\t\t\t\t\t\t%s%s tip : enter the corresponding number to play%s\n",RED,DULL,RESET);
    
    do{;
wrongChoice:
        printf("\n\t\t\t\t\t%sPlayer %s turn\nEnter the corresponding number : %s",BLUE,player?"player 1 [X]":"player 2 [O]",RESET);
        scanf("%d",&a);
        if(b[a]=='X'||(int)b[a]=='O'||a>9||a<0){
            printf("\n\n%sI N V A L I D  C H O I C E %s\n\n",RED,RESET);
            goto wrongChoice;
        }else{
            b[a]=player?'X':'O';
            player=!player;
            movesPlayed++;
    printBoard(a,player);
        }
    }while (!(b[1] == b[2] && b[2] == b[3]) && !(b[4] == b[5] && b[5] == b[6]) && !(b[7] == b[8] && b[8] == b[9]) &&
   !(b[1] == b[4] && b[4] == b[7]) && !(b[2] == b[5] && b[5] == b[8]) && !(b[3] == b[6] && b[6] == b[9]) &&
   !(b[7] == b[5] && b[5] == b[3]) && !(b[1] == b[5] && b[5] == b[9]) && movesPlayed < 9);

    if(movesPlayed < 9){
    printf("\n\n\n%s",BGred);
   printf("\t\t\t\t\t****************************%s\n",RESET);
   printf("\t\t\t\t\t%s*                          *%s\n",BGred,RESET);
   printf("\t\t\t\t\t%s*  player %d is the winner  *%s\n",BGred,player+1,RESET);
   printf("\t\t\t\t\t%s*                          *%s\n",BGred,RESET);
   printf("\t\t\t\t\t%s****************************%s\n",BGred,RESET);
    }else{
    printf("\n\n\n%s",BGred);
   printf("\t\t\t\t\t****************************%s\n",RESET);
   printf("\t\t\t\t\t%s*                          *%s\n",BGred,RESET);
   printf("\t\t\t\t\t%s*       IT'S A TIE         *%s\n",BGred,RESET);
   printf("\t\t\t\t\t%s*                          *%s\n",BGred,RESET);
   printf("\t\t\t\t\t%s****************************%s\n",BGred,RESET);
    }
    
    return 0;
}




