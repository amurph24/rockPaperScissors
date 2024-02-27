#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCORECOUNT 2
#define SCOREFILE_PATH "/var/lib/rockPaperScissors/score.txt" // replace score.txt with this macro before completing project

void read_scores(int* player_score, int* computer_score) {
    FILE *fp = fopen("score.txt", "r");
    const char s[3] = ", ";
    char *token;
    int count = 0;
    int *scores = (int*) malloc(sizeof(int)*SCORECOUNT);
    if (fp != NULL)
    {
        char line[40];
        fgets(line, sizeof(line), fp);
        token = strtok(line, s);
        while (token != NULL)
        {
            *scores = atoi(token);
            scores++; count++;
            token = strtok(NULL, s);
        }
        scores -= count;
    } else {
        *scores = 0;
        *(scores + 1) = 0;
        fopen("score.txt", "a");
    }

    *player_score = *scores;
    *computer_score = *(scores+1);
    free(scores);

    return;
}

int write_scores(int* player_score, int* computer_score) {
    FILE *fp;
    if (fp = fopen("score.txt", "r+")) {
        fprintf(fp, "%d, %d", *player_score, *computer_score);
    } else {
        printf("scores could not be saved, sorry\n");
    }
    return 0;
}