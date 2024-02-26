#include <stdio.h>
#include "gameProcesses.h"

int enterRPSMenu() {
    
    time_t t;
    srand((unsigned) time(&t));

    int *scores = read_scores();
    char option = 0;
    int *player_score = scores;
    int *computer_score = scores+1;

    while (option != '4')
    {
        system("clear");
        printf("=====================================================================\n");
        printf("This is Rock Paper Scissors, your score vs the computer is: %d - %d\n\n", *player_score, *computer_score);

        printf( "What would you like to do?\n"
                " (1) play\n"
                " (2) rules/controls\n"
                " (3) reset scores (cannot be reversed)\n"
                " (4) save scores and quit\n"
                "=====================================================================\n"
                "Choice: ");
        scanf("\n%c", &option);

        switch (option)
        {
            case '1': play_round(player_score, computer_score);break;
            case '2': show_rules();break;
            case '3': reset_scores(player_score, computer_score);break;
            case '4': ;break;
            default: printf("invalid input\n"); sleep(3);
        }

    }

    write_scores(player_score, computer_score);
    
    free(scores);
    system("clear");
    return 0;
}

int main()
{
    enterRPSMenu();
    return 0;
}