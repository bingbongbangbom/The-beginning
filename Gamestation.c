
#include <stdio.h>

//including the games
#include "ttt.h" //tick tack toe
#include "rockpapersword.h" //rock paper scissors

int main(void) {

    start:

    char x;

    printf("\n\n\nType r to play rock paper scissors against the machine\n\n\n"
           "Type t to play ticktacktoe against a friend, and anything else to exit");
    scanf(" %c", &x);

    //choosing the game you want to play.
    switch(x) {
        case 'r':
            rpc();//rock paper scissors
            goto start;
        case 't':
            ttt();//tick tack toe
            goto start;
        default://do i even need this?
            break;
    }

    printf("\n\n\n\nGoodbye see ya!\n\n\n\n");

    return 0;
}

