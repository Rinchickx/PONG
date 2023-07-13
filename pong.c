// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI
#include <stdio.h>

void print_table(int FIRST_PLAYER, int SECOND_PLAYER, int FIRST_PLAYER_RACKET, int SECOND_PLAYER_RACKET,
                 int BALL_X, int BALL_Y);
void movement(int ANGLE_X, int ANGEL_Y, int BALL_X, int BALL_Y, int FIRST_PLAYER, int SECOND_PLAYER,
              int FIRST_PLAYER_RACKET, int SECOND_PLAYER_RACKET);
void check_win(int FIRST_PLAYER, int SECOND_PLAYER);

int main() {
    int FIRST_PLAYER = 0;           // очки у первого игрока
    int SECOND_PLAYER = 0;          // очки у второго игрока
    int FIRST_PLAYER_RACKET = 13;   // координата ракетки первого игрока
    int SECOND_PLAYER_RACKET = 13;  // координата ракетки второго игрока
    int BALL_X = 42;                // Координата X мяча
    int BALL_Y = 13;                // Координата Y мяча
    int ANGLE_X = 1;                // Направление мяча по оси X
    int ANGLE_Y = 1;                // Направление мяча по оси Y

    movement(ANGLE_X, ANGLE_Y, BALL_X, BALL_Y, FIRST_PLAYER, SECOND_PLAYER, FIRST_PLAYER_RACKET,
             SECOND_PLAYER_RACKET);

    return 0;
}

// Вывод текущего поля
void print_table(int FIRST_PLAYER, int SECOND_PLAYER, int FIRST_PLAYER_RACKET, int SECOND_PLAYER_RACKET,
                 int BALL_X, int BALL_Y) {
    for (int i = 0; i < 256; i++) printf("\n");

    printf("СЧЕТ: %d - %d\n", FIRST_PLAYER, SECOND_PLAYER);

    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 82; j++)
            if (i == 0 || i == 26)
                printf("%c", '-');
            else if (j == 0 || j == 81)
                printf("%c", '|');
            else if (j == 1 && FIRST_PLAYER_RACKET - 1 <= i && i <= FIRST_PLAYER_RACKET + 1)
                printf("]");
            else if (j == 80 && SECOND_PLAYER_RACKET - 1 <= i && i <= SECOND_PLAYER_RACKET + 1)
                printf("[");
            else if (j == BALL_X && i == BALL_Y)
                printf("o");
            else if (j == 41 || j == 42)
                printf("|");
            else
                printf(" ");

        printf("\n");
    }

    if (FIRST_PLAYER == 21 || SECOND_PLAYER == 21) check_win(FIRST_PLAYER, SECOND_PLAYER);
}

// Функция отвечающая за передвижение
void movement(int ANGLE_X, int ANGLE_Y, int BALL_X, int BALL_Y, int FIRST_PLAYER, int SECOND_PLAYER,
              int FIRST_PLAYER_RACKET, int SECOND_PLAYER_RACKET) {
    char press;

    print_table(FIRST_PLAYER, SECOND_PLAYER, FIRST_PLAYER_RACKET, SECOND_PLAYER_RACKET, BALL_X, BALL_Y);

    if (FIRST_PLAYER == 21 || SECOND_PLAYER == 21) {
        FIRST_PLAYER = 0;
        SECOND_PLAYER = 0;
    }

    scanf("%c", &press);

    if (press == 'a' || press == 'z' || press == 'k' || press == 'm' || press == ' ') {
        if (press == 'a' && FIRST_PLAYER_RACKET != 2)
            FIRST_PLAYER_RACKET -= 1;
        else if (press == 'z' && FIRST_PLAYER_RACKET != 24)
            FIRST_PLAYER_RACKET += 1;
        else if (press == 'k' && SECOND_PLAYER_RACKET != 2)
            SECOND_PLAYER_RACKET -= 1;
        else if (press == 'm' && SECOND_PLAYER_RACKET != 24)
            SECOND_PLAYER_RACKET += 1;

        if (ANGLE_X == 1)
            BALL_X++;
        else
            BALL_X--;

        if (ANGLE_Y == 1)
            BALL_Y++;
        else
            BALL_Y--;

        if (BALL_Y == 1 || BALL_Y == 25) ANGLE_Y *= -1;

        if ((BALL_X == 2 && FIRST_PLAYER_RACKET - 1 <= BALL_Y && BALL_Y <= FIRST_PLAYER_RACKET + 1) ||
            (BALL_X == 79 && SECOND_PLAYER_RACKET - 1 <= BALL_Y && BALL_Y <= SECOND_PLAYER_RACKET + 1))
            ANGLE_X *= -1;

        if (BALL_X == 1 || BALL_X == 80) {
            if (BALL_X == 1) SECOND_PLAYER += 1;
            if (BALL_X == 80) FIRST_PLAYER += 1;

            BALL_X = 42;
            BALL_Y = 13;
        }
    }

    movement(ANGLE_X, ANGLE_Y, BALL_X, BALL_Y, FIRST_PLAYER, SECOND_PLAYER, FIRST_PLAYER_RACKET,
             SECOND_PLAYER_RACKET);
}

// проверка кто победил
void check_win(int FIRST_PLAYER, int SECOND_PLAYER) {
    if (FIRST_PLAYER == 21) printf("ПЕРВЫЙ ИГРОК ПОБЕДИЛ!");
    if (SECOND_PLAYER == 21) printf("ВТОРОЙ ИГРОК ПОБЕДИЛ!");
}
