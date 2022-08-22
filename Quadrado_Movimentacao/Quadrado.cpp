#include "main.h"

void quadrado(float posX, float posY){    
    glBegin(GL_POLYGON);
    glVertex2f(posX, 1 + posY);
    glVertex2f(posX, -1 + posY);
    glVertex2f(2 + posX, -1 + posY);
    glVertex2f(2 + posX, 1 + posY);
    glEnd();
}