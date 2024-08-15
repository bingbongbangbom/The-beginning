//
// Created by abrah on 8/14/2024.
//
#ifndef TTT_H
#define TTT_H

char board[3][3];
char kal[3][3];

void printboard() {
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
}


void clearboard() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            board[i][j]=' ';
            kal[i][j]=' ';
        }
    }
}
//This is to make shure that the game stops when all the spaces on the boards are filled
int checkfreespaces() {
    int freespaces = 9;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if(board[j][i] != ' ') {
                freespaces = freespaces-1;
            }
        }
    }
    return freespaces;
}

void playermoveone() {
    amogus:
    int x;
    int y;
    printf("\n Player 1 Enter a columb number from 1 to 3. \n");
    scanf("\n %d", &x );
    printf("\n Plaer 1 Enter a row number from 1 to 3. \n");
    scanf("\n %d", &y );
    if(board[y-1][x-1] == ' ') {
        board[y-1][x-1]='X';
    }
    else {
        printf("The spot is taken try again");
        goto amogus;
    }
}



void playermovetwo() {
    sussy:
    int x;
    int y;
    printf("\nplayer 2 Enter a columb number from 1 to 3. \n");
    scanf("\n %d", &x );
    printf("\nplayer 2 Enter a row number from 1 to 3. \n");
    scanf("\n %d", &y );
    if(board[y-1][x-1] == ' ') {
        board[y-1][x-1]='O';
    }
    else {
        printf("The spot is taken try again");
        goto sussy;
    }
}



//builds the matrix used in calculations, sorry i know its messy.
int apekatt() {

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {

            switch(board[j][i]) {

                case 'X':
                    kal[j][i]=1;
                break;

                case 'O':
                    kal[j][i]=-1;
                break;

                default:
                    kal[j][i]=0;
                break;
            }
        }
    }


        //player 1
    if ((kal[0][0]+kal[0][1]+kal[0][2])==3 || (kal[1][0]+kal[1][1]+kal[1][2])==3 || (kal[2][0]+kal[2][1]+kal[2][2])==3 ) {
        return 1;
    }
    if ((kal[0][0]+kal[1][0]+kal[2][0])==3 || (kal[0][1]+kal[1][1]+kal[2][1])==3 || (kal[0][2]+kal[1][2]+kal[2][2])==3 ) {
        return 1;
    }
    if ((kal[0][0]+kal[1][1]+kal[2][2])==3 || (kal[2][0]+kal[1][1]+kal[0][2])==3) {
        return 1;
    }
    //player 2
    if ((kal[0][0]+kal[0][1]+kal[0][2])==-3 || (kal[1][0]+kal[1][1]+kal[1][2])==-3 || (kal[2][0]+kal[2][1]+kal[2][2])==-3 ) {
        return -1;
    }
    if ((kal[0][0]+kal[1][0]+kal[2][0])==-3 || (kal[0][1]+kal[1][1]+kal[2][1])==-3 || (kal[0][2]+kal[1][2]+kal[2][2])==-3 ) {
        return -1;
    }
    if ((kal[0][0]+kal[1][1]+kal[2][2])==-3 || (kal[2][0]+kal[1][1]+kal[0][2])==-3) {
        return -1;
    }
    else return 0;
}



void ttt()
{
    again:
    clearboard();
    printboard();
    start:
    checkfreespaces();
    playermoveone();
    if (apekatt()==1) {
        printf("\n\n\nplayer one won!\n\n\n");
        goto end;
    }
    if (checkfreespaces() == 0) {
        printf("draw!");
        goto end;
    }
    printboard();
    playermovetwo();
    if (apekatt()==-1) {
        printf("\n\n\nplayer two won!\n\n\n");
        goto end;
    }
    printboard();
    goto start;
    end:
    printf("\n Press r to go again and other letter to exit. \n");
    int l;
    scanf("\n %c", &l);
    if (l=='r') {
        goto again;
    }

}
#endif //TTT_H
