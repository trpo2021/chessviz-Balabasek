#include "move.h"
#include <stdio.h>
#include <string.h>

void display(figure desk[8][8]);

void input(coordinate *a, coordinate *b, char arr[]);
coordinate parserCoord(const char *const arr);

void createDesk(figure desk_o[8][8]) {

  figure desk[8][8] =   {{{'r', }, {'n', }, {'b', }, {'q', }, {'k', }, {'b', }, {'n', }, {'r', }},
						{{'p', }, {'p', }, {'p', }, {'p', }, {'p', }, {'p', }, {'p', }, {'p', }},
						{{' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }},
						{{' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }},
						{{' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }},
						{{' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }, {' ', }},
						{{'P', }, {'P', }, {'P', }, {'P', }, {'P', }, {'P', }, {'P', }, {'P', }},
						{{'R', }, {'N', }, {'B', }, {'Q', }, {'K', }, {'B', }, {'N', }, {'R', }}
						};

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

int main() {
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
      /*    case 'R':
              move_rook(desk, a, b);
              break;
          case 'R':
              move_rook(desk, a, b);
              break;*/
    }
    display(desk);
  }

  return 0;
}

void display(figure desk[8][8]) {
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

coordinate parserCoord(const char *const arr) {
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
