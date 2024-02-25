#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int* read_data() {
    FILE *fp = fopen("score.txt", "r");
    const char s[3] = ", ";
    char *token;
    int count = 0;
    int temp;
    int *scores = (int*) malloc(sizeof(int)*2);
    if (fp != NULL)
    {
        char line[40];
        fgets(line, sizeof(line), fp);
        token = strtok(line, s);
        // TODO: return token reference and parse in main()
        while (token != NULL)
        {
            temp = atoi(token);
            *scores = temp;
            scores++; count++;
            token = strtok(NULL, s);
        }
        scores -= count;
    } else {
        *scores = 0;
        *(scores + 1) = 0;
        fopen("score.txt", "a");
    }
    return scores;
}

void play_round(int* player_score, int* computer_score) {
    system("cls");
    char pc_choice = (rand() % 3);
    char player_choice;

    do {
        printf("=====================================================================\n");
        printf("Pick scissors (s), paper (p), or rock (r)\n");
        printf(" (s) scissors\n");
        printf(" (p) paper\n");
        printf(" (r) rock\n");
        printf("=====================================================================\n");
        printf("Choice: ");
        scanf(" %c", &player_choice);

        if (player_choice != 112 && player_choice != 114 && player_choice != 115) {
            printf("Pick a valid character\n\n");
            player_choice = 0;
        }

    } while (!player_choice);

    switch (pc_choice)
    {
        case 0: pc_choice = 112;break;
        case 1: pc_choice = 114;break;
        case 2: pc_choice = 115;break;
        default: printf("internal error");
    }
    printf("%c vs %c\n", player_choice, pc_choice);

    switch (player_choice - pc_choice)
    {
        // loss
        case -3:; case 1:; case 2:
            printf("You lost!");
            (*computer_score)++;
            break;
        // win
        case -2:; case -1:; case 3:
            printf("You won!");
            (*player_score)++;
            break;
        // draw
        case 0:
            printf("You drew!");
            break;

        default:
            printf("invalid result, something went wrong");
    }
    Sleep(3*1000);
    return;
}

void show_rules(){
    system("cls");
    printf("=====================================================================\n");
    printf("Pick rock, paper or scissors. The computer will also pick rock, paper or scissors.\n");
    printf(" Rock beats Scissors\n");
    printf(" Scissors beat paper\n");
    printf(" Paper beats rock\n\n");

    printf(" (1) Go back\n");
    printf("=====================================================================\n");
    printf("Choice: ");

    int input = 0;
    while(input != 1) {
        scanf("%d", &input);
    }
}

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    int *scores = read_data();
    int option = 0;
    int *player_score = scores;
    int *computer_score = scores+1;

    while (option != 3)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("This is Rock Paper Scissors, your score vs the computer is: %d - %d\n\n", *player_score, *computer_score);

        printf("What would you like to do?\n");
        printf(" (1) play\n");
        printf(" (2) rules/controls\n");
        printf(" (3) quit\n");
        printf("=====================================================================\n");
        printf("Choice: ");
        scanf("%d", &option);
        switch (option)
        {
            case 1: play_round(player_score, computer_score);break;

            case 2: show_rules();break;

            case 3: ;break;

            default: printf("invalid input\n");
        }

    }

    
    FILE *fp = fopen("score.txt", "r+");
    fprintf(fp, "%d, %d", *player_score, *computer_score);

    free(scores);
    system("cls");
    return 0;
}