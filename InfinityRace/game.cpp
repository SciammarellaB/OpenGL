#include "main.h"

float posX, posY;
int posXState;

void game()
{
    glTranslatef(0.0, 0.0, -10.0);
    car();
}

void update()
{
    posX += 0.15;
}