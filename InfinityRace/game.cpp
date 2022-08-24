#include "main.h"

#define MAX 5

Street rua[MAX];

float x;

void setup(){
    glClearColor(0.72, 0.92, 1.0, 1.0);
    glClearDepth(1.0);
}

void game()
{
    for(int i = 0; i < MAX; i++){
        rua[i].position(0, -5, (-4 * i) + x);
        rua[i].scale(5, 0.15, 2);
        rua[i].model();
    }
}

void update()
{
    x += 0.05;
}