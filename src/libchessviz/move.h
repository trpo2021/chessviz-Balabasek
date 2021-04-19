#pragma once

typedef struct {
    int x;
    int y;
} coordinate;

typedef struct {
    char name;
    coordinate coord;
} figure;

void move_pown(figure desk[8][8], coordinate, coordinate);
void move_king(figure desk[8][8], coordinate, coordinate);
void move_knight(figure desk[8][8], coordinate, coordinate);
void move_rook(figure desk[8][8], coordinate, coordinate);
void swap(figure desk[8][8], coordinate a, coordinate b);
