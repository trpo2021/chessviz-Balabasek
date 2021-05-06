#include "libchessviz/desk.h"
#include "libchessviz/move.h"
#include <string.h>

int main()
{
    figure desk[8][8];
    createDesk(desk);
    display(desk);

    coordinate a;
    coordinate b;

    char arr[6];

    while (1) {
        fgets(arr, sizeof(arr), stdin);
        a = parserCoord(arr);
        b = parserCoord(&arr[3]);
        getchar();
        switch (desk[a.x][a.y].name) {
        case 'p':
            move_pown(desk, a, b);
            break;
        case 'P':
            move_pown(desk, a, b);
            break;
        case 'k':
            move_king(desk, a, b);
            break;
        case 'K':
            move_king(desk, a, b);
            break;
        case 'N':
            move_knight(desk, a, b);
            break;
        case 'n':
            move_knight(desk, a, b);
            break;
        case 'R':
            move_rook(desk, a, b);
            break;
        case 'r':
            move_rook(desk, a, b);
            break;
        case 'B':
            move_bishop(desk, a, b);
            break;
        case 'b':
            move_bishop(desk, a, b);
            break;
        case 'Q':
            move_queen(desk, a, b);
            break;
        case 'q':
            move_queen(desk, a, b);
            break;
        }
        display(desk);
    }

    return 0;
}
