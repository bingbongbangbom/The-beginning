#ifndef rockpapersword_H
#define rockpapersword_H
#include <time.h>
#include <stdlib.h>
char a = ' ';

//The rools for the game.
int game(char player, char computer)
{
    if(player == computer)
        return -1;
    if(player == 'r' && computer == 'p')
        return 0;
    if(player == 'r' && computer == 's')
        return 1;
    if(player == 'p' && computer == 'r')
        return 1;
    if(player == 'p' && computer == 's')
        return 0;
    if(player == 's' && computer == 'r')
        return 0;
    if(player == 's' && computer == 'p')
        return 1;
    if(player != 's' && player != 'r' && player != 'p')
        return 2;

}

void rpc()//Running the game
{
    restart:

    char you, computer, result;

    // Chooses the random number
    srand(time(NULL));

    // Generate a random number to decide computer's choice
    int n = rand() % 3;

    // Assign computer's choice based on probability
    switch(n){
        case(0):
            computer = 'r';
            break;

        case(1):
            computer = 'p';
            break;

        default:
            computer = 's';
            break;
    }

    printf("\n\n\n\n\t\t\t\tEnter r for ROCK, p for PAPER, s for SCISSOR\n\n\n\n\t\t\t\t");

    // Input from the user
    scanf(" %c", &you);  // Use " %c" to handle the newline character

    // Function Call to play the game
    result = game(you, computer);

    // Check the result and print the appropriate message
    switch (result) {
        case -1:
            printf("\n\n\t\t\t\tDraw, you both loose\n\n\n");
            break;

        case 1:
            printf("\n\n\t\t\t\tWow! You won against random chance, impressive...\n\n\n");
            break;

        case 0:
            printf("\n\n\t\t\t\tSucks to suck asshat. You lost...\n\n\n");
            break;

        default:
            printf("\n\n\t\t\t\tLearn to type or else!\n\n\n");
            break;
    }

    punk:

    printf("Type 'e' to exit and 'r' to restart: ");
    scanf(" %c", &a);  // Reading a single character input

    switch(a){
        case 'r':
            goto restart;
            break;

        case 'e':
            printf("GOOD BYE DUMBASS!");
            break;

        default:// If someone tries to be funny
            printf("Trying to be funny? Let's try again. Do what I tell you to do this time >:(.\n");
            goto punk;
            break;
    }
}
#endif