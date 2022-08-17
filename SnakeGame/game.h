#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define LEFT -2
#define RIGHT 2
#define snakeMax 60

void initGrid(int, int);
void drawGrid();
void drawSnake();
void drawFood();
int random(int, int);

#endif