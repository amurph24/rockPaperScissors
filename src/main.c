#include "score.h"
#include "gameScreens.h"
#include <stdlib.h>

int rps() {
    // TODO: change read_scores() --> read_scores(player_score, computer_score)
    int *scores = read_scores();
    int *player_score = scores;
    int *computer_score = scores+1;

    enter_menu(player_score, computer_score);
    write_scores(player_score, computer_score);
    free(scores);
    return 0;
}

int main()
{
    rps();
    return 0;
}