#include <math.h>
#include <stdio.h>

struct {
    int x;
    int y;
} typedef coordinate;

struct {
    char name;
    coordinate coord;
} typedef figure;

void display(figure desk[8][8]);

void createDesk(figure desk_o[8][8])
{
    figure desk[8][8]
            = {{{
                        'r',
                },
                {
                        'n',
                },
                {
                        'b',
                },
                {
                        'q',
                },
                {
                        'k',
                },
                {
                        'b',
                },
                {
                        'n',
                },
                {
                        'r',
                }},
               {{
                        'p',
                },
                {
                        'p',
                },
                {
                        'p',
                },
                {
                        'p',
                },
                {
                        'p',
                },
                {
                        'p',
                },
                {
                        'p',
                },
                {
                        'p',
                }},
               {{
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                }},
               {{
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                }},
               {{
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                }},
               {{
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                },
                {
                        ' ',
                }},
               {{
                        'P',
                },
                {
                        'P',
                },
                {
                        'P',
                },
                {
                        'P',
                },
                {
                        'P',
                },
                {
                        'P',
                },
                {
                        'P',
                },
                {
                        'P',
                }},
               {{
                        'R',
                },
                {
                        'N',
                },
                {
                        'B',
                },
                {
                        'Q',
                },
                {
                        'K',
                },
                {
                        'B',
                },
                {
                        'N',
                },
                {
                        'R',
                }}};

    for (int i = 0; i < 8; i++) // set coordinates
    {
        for (int j = 0; j < 8; j++) {
            desk[i][j].coord.x = i;
            desk[i][j].coord.y = j;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            desk_o[i][j] = desk[i][j];
        }
    }
}

int main()
{
    figure desk[8][8];
    createDesk(desk);
    display(desk);

    return 0;
}

void display(figure desk[8][8])
{
    char gorizont[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (int i = 0; i < 8; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%3c", desk[i][j].name);
        }
        printf("\n");
    }
    printf("  _________________________\n");
    printf("  ");

    for (int i = 0; i < 8; i++) {
        printf("%3c", gorizont[i]);
    }

    printf("\n\n\n");
}
