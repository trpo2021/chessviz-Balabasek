#pragma once

typedef struct coord
{
	int x;
	int y;
}coordinate;

typedef struct figure
{
	char name;
	coordinate coord;
}figure;

void move_pown(figure  desk[8][8], coordinate , coordinate);
void move_king(figure  desk[8][8], coordinate , coordinate);
void move_knight(figure  desk[8][8], coordinate , coordinate);
void move_rook(figure  desk[8][8], coordinate , coordinate);
void swap(figure  desk[8][8], coordinate a, coordinate b);
