#include "move.h"
#include <stdio.h>
#include <stdlib.h>

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

void move_pown(figure desk[8][8], coordinate start, coordinate end)
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
            printf(" Peshka \n");
        } else {
            printf("	uncorrect movePown2.\n\n\n");
        }
    } else {
        printf("	uncorrect movePown.\n\n\n");
    }
}
void move_king(figure desk[8][8], coordinate start, coordinate end)
{
    int step = end.x - start.x;
    int step2 = end.y - start.y;
    if ((desk[end.x][end.y].name == ' ')
        && (((abs(step) == 1) && (abs(step2) == 0))
            || ((abs(step2) == 1) && (abs(step) == 0))
            || ((abs(step) == 1) && (abs(step2) == 1)))) {
        swap(desk, start, end);
        printf(" korol \n");
    } else {
        printf("	uncorrect moveKing.\n\n\n");
    }
}

void move_knight(figure desk[8][8], coordinate start, coordinate end)
{
    int step = end.x - start.x;
    int step2 = end.y - start.y;
    if ((((abs(step2) == 1) && (abs(step) == 2))
         || ((abs(step2) == 2) && (abs(step) == 1)))
        && (desk[end.x][end.y].name == ' ')) {
        swap(desk, start, end);
        printf(" Konb \n");
    } else {
        printf("	uncorrect moveKnight.\n\n\n");
    }
}
