#include <stdio.h>


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

    //TODO make this more maintainable and updatable, remove magic numbers; use adjacency matrix
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