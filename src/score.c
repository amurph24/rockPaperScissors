#include <stdio.h>

int* read_scores() {
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

int write_scores(int* player_score, int* computer_score) {
    FILE *fp;
    if (fp = fopen("score.txt", "r+")) {
        fprintf(fp, "%d, %d", *player_score, *computer_score);
    } else {
        printf("scores could not be saved, sorry\n");
    }
    return 0;
}