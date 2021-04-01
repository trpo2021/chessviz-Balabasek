#pragma once

struct coord
{
	int x;
	int y;
}typedef coordinate;

struct figure
{
	char name;
	coordinate coord;
}typedef figure;

void move_pown(figure  desk[8][8], coordinate , coordinate);
void move_king(figure  desk[8][8], coordinate , coordinate);
void move_knight(figure  desk[8][8], coordinate , coordinate);
void move_rook(figure  desk[8][8], coordinate , coordinate);
void swap(figure  desk[8][8], coordinate a, coordinate b);
