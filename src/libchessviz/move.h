#pragma once

typedef struct {
    int x;
    int y;
} coordinate;

typedef struct {
    char name;
    coordinate coord;
} figure;

coordinate parserCoord(const char* const arr);
int move_pown(figure desk[8][8], coordinate, coordinate);
int move_king(figure desk[8][8], coordinate, coordinate);
int move_knight(figure desk[8][8], coordinate, coordinate);
int move_rook(figure desk[8][8], coordinate, coordinate);
void swap(figure desk[8][8], coordinate, coordinate);
int move_bishop(figure desk[8][8], coordinate, coordinate);
int move_queen(figure desk[8][8], coordinate, coordinate);
