#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void play_round(int* player_score, int* computer_score) {
    system("clear");
    char pc_choice = (rand() % 3);
    char player_choice;

    do {
        printf( "=====================================================================\n"
                "Pick scissors (s), paper (p), or rock (r)\n"
                " (s) scissors\n"
                " (p) paper\n"
                " (r) rock\n"
                "=====================================================================\n"
                "Choice: ");
        scanf(" %c", &player_choice);

        if (player_choice != 112 && player_choice != 114 && player_choice != 115) {
            printf("Pick a valid character\n\n");
            player_choice = 0;
        }

    } while (!player_choice);

    //TODO make this more maintainable and updatable, remove magic numbers; use adjacency matrix and MACROS
    switch (pc_choice)
    {
        case 0: pc_choice = 'p';break;
        case 1: pc_choice = 'r';break;
        case 2: pc_choice = 's';break;
        default: printf("internal error");
    }
    printf("%c vs %c\n", player_choice, pc_choice);

    switch (player_choice - pc_choice)
    {
        // loss
        case -3:; case 1:; case 2:
            printf("You lost!\n");
            (*computer_score)++;
            break;
        // win
        case -2:; case -1:; case 3:
            printf("You won!\n");
            (*player_score)++;
            break;
        // draw
        case 0:
            printf("You drew!\n");
            break;

        default:
            printf("invalid result, something went wrong\n");
    }
    sleep(3);
    return;
}

int show_rules(){
    system("clear");
    printf("=====================================================================\n"
            "Pick rock, paper or scissors. The computer will also pick rock, paper or scissors.\n"
            " Rock beats Scissors\n"
            " Scissors beat paper\n"
            " Paper beats rock\n\n"

            " (1) Go back\n"
            "=====================================================================\n"
            "Choice: ");

    char input = 0;
    while(input != '1') {
        scanf("%c", &input);
    }
    return 0;
}

int reset_scores(int* score1, int* score2) {
    *score1 = *score2 = 0;
    return 0;
}

int enter_menu(int* player_score, int* computer_score) {
    time_t t;
    srand((unsigned) time(&t));
    char option = 0;

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
    system("clear");
    return 0;
}