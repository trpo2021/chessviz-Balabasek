#include "move.h"
#include <stdio.h>
#include <stdlib.h>

coordinate parserCoord(const char* const arr)
{
    coordinate a;

    switch (arr[0]) {
    case 'a':
        a.y = 0;
        break;

    case 'b':
        a.y = 1;
        break;

    case 'c':
        a.y = 2;
        break;

    case 'd':
        a.y = 3;
        break;

    case 'e':
        a.y = 4;
        break;

    case 'f':
        a.y = 5;
        break;

    case 'g':
        a.y = 6;
        break;

    case 'h':
        a.y = 7;
        break;

    default:
        printf("	uncorrect move.\n\n\n");
    }

    a.x = (int)arr[1] - '0' - 1;

    return a;
}

void swap(figure desk[8][8], coordinate a, coordinate b)
{
    coordinate temp;
    temp.x = a.x;
    temp.y = a.y;
    char name = desk[a.x][a.y].name;

    desk[a.x][a.y] = desk[b.x][b.y];
    desk[b.x][b.y].coord.x = temp.x;
    desk[b.x][b.y].coord.y = temp.y;
    desk[b.x][b.y].name = name;
}

int move_pown(figure desk[8][8], coordinate start, coordinate end)
{
    int step = end.x - start.x;
    int step2 = end.y - start.y;
    if (((((start.x == 1 && desk[2][start.y].name == ' ')
           || (start.x == 6 && desk[5][start.y].name == ' '))
          && (abs(step) == 2))
         || ((abs(step) == 1) && (desk[end.x][end.y].name == ' ')))
        && (step2 == 0)) {
        if ((desk[start.x][start.y].name == 'p' && (step) > 0)
            || (desk[start.x][start.y].name == 'P' && (step) < 0)) {
            swap(desk, start, end);
            return 0;
        } else {
            printf("	uncorrect move Pown.\n\n\n");
            return 1;
        }
    } else {
        printf("	uncorrect move Pown.\n\n\n");
        return 1;
    }
}
int move_king(figure desk[8][8], coordinate start, coordinate end)
{
    int step = end.x - start.x;
    int step2 = end.y - start.y;
    if ((desk[end.x][end.y].name == ' ')
        && (((abs(step) == 1) && (abs(step2) == 0))
            || ((abs(step2) == 1) && (abs(step) == 0))
            || ((abs(step) == 1) && (abs(step2) == 1)))) {
        swap(desk, start, end);
        return 0;
    } else {
        printf("	uncorrect move King.\n\n\n");
        return 1;
    }
}

int move_knight(figure desk[8][8], coordinate start, coordinate end)
{
    int step = end.x - start.x;
    int step2 = end.y - start.y;
    if ((((abs(step2) == 1) && (abs(step) == 2))
         || ((abs(step2) == 2) && (abs(step) == 1)))
        && (desk[end.x][end.y].name == ' ')) {
        swap(desk, start, end);
        return 0;
    } else {
        printf("	uncorrect move Knight.\n\n\n");
        return 1;
    }
}
int move_rook(figure desk[8][8], coordinate start, coordinate end)
{
    int step = end.x - start.x;
    int step2 = end.y - start.y;
    int i = 0;
    if ((((abs(step) != 0) && (abs(step2) == 0))
         || ((abs(step) == 0) && (abs(step2) != 0)))
        && (desk[end.x][end.y].name == ' ')) {
        if (start.y > end.y) {
            for (i = start.y; i > end.y; i--) {
                if (desk[end.x][i - 1].name != ' ') {
                    i = -10;
                    break;
                }
            }
            if (i == -10) {
                printf("	uncorrect move Rook.\n\n\n");
                return 1;
            } else {
                swap(desk, start, end);
                return 0;
            }
        } else if (start.y < end.y) {
            for (i = start.y; i < end.y; i++) {
                if (desk[end.x][i + 1].name != ' ') {
                    i = -10;
                    break;
                }
            }
            if (i == -10) {
                printf("	uncorrect move Rook.\n\n\n");
                return 1;
            } else {
                swap(desk, start, end);
                return 0;
            }
        }
        if (start.x > end.x) {
            for (i = start.x; i > end.x; i--) {
                if (desk[i - 1][end.y].name != ' ') {
                    i = -12;
                    break;
                }
            }
            if (i == -12) {
                printf("	uncorrect move Rook.\n\n\n");
                return 1;
            } else {
                swap(desk, start, end);
                return 0;
            }
        } else if (start.x < end.x) {
            for (i = start.x; i < end.x; i++) {
                if (desk[i + 1][end.y].name != ' ') {
                    i = -12;
                    break;
                }
            }
            if (i == -12) {
                printf("	uncorrect move Rook.\n\n\n");
                return 1;
            } else {
                swap(desk, start, end);
                return 0;
            }
        } else {
            printf("	uncorrect move Rook.\n\n\n");
            return 1;
        }
    } else {
        printf("	uncorrect move Rook.\n\n\n");
        return 1;
    }
}
int move_bishop(figure desk[8][8], coordinate start, coordinate end)
{
    int step = end.x - start.x;
    int step2 = end.y - start.y;
    int i = 0;
    int j = 0;
    if ((abs(step) == abs(step2)) && (desk[end.x][end.y].name == ' ')) {
        if ((start.y > end.y) && (start.x > end.x)) {
            j = start.x;
            for (i = start.y; i > end.y; i--) {
                if (desk[j - 1][i - 1].name != ' ') {
                    i = -10;
                    break;
                }
                j--;
            }
            if (i == -10) {
                printf("	uncorrect move Bishop.\n\n\n");
                return 1;
            } else {
                swap(desk, start, end);
                return 0;
            }
        } else if ((start.y < end.y) && (start.x < end.x)) {
            j = start.x;
            for (i = start.y; i < end.y; i++) {
                if (desk[j + 1][i + 1].name != ' ') {
                    i = -10;
                    break;
                }
                j++;
            }
            if (i == -10) {
                printf("	uncorrect move Bishop.\n\n\n");
                return 1;
            } else {
                swap(desk, start, end);
                return 0;
            }
        } else if ((start.y < end.y) && (start.x > end.x)) {
            j = start.x;
            for (i = start.y; i < end.y; i++) {
                if (desk[j - 1][i + 1].name != ' ') {
                    i = -10;
                    break;
                }
                j--;
            }
            if (i == -10) {
                printf("	uncorrect move Bishop.\n\n\n");
                return 1;
            } else {
                swap(desk, start, end);
                return 0;
            }
        } else if ((start.y > end.y) && (start.x < end.x)) {
            j = start.x;
            for (i = start.y; i > end.y; i--) {
                if (desk[j + 1][i - 1].name != ' ') {
                    i = -10;
                    break;
                }
                j++;
            }
            if (i == -10) {
                printf("	uncorrect move Bishop.\n\n\n");
                return 1;
            } else {
                swap(desk, start, end);
                return 0;
            }
        } else {
            printf("	uncorrect move Bishop.\n\n\n");
            return 1;
        }
    } else {
        printf("	uncorrect move Bishop.\n\n\n");
        return 1;
    }
}
int move_queen(figure desk[8][8], coordinate start, coordinate end)
{
    int step = end.x - start.x;
    int step2 = end.y - start.y;
    if ((((abs(step) != 0) && (abs(step2) == 0))
         || ((abs(step) == 0) && (abs(step2) != 0)))
        && (desk[end.x][end.y].name == ' ')) {
        return move_rook(desk, start, end);
    } else if ((abs(step) == abs(step2)) && (desk[end.x][end.y].name == ' ')) {
        return move_bishop(desk, start, end);
    } else {
        return 1;
    }
}
