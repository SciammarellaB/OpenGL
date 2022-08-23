#include "main.h"

#define MAX 50

// Car carro1, carro2;
Street rua[MAX];

float x;

void game()
{   
    // carro1.position(-x, -2, -25);
    // carro1.scale(5, 0.15, 3);
    // carro1.model();

    // carro2.position(0, -2, -25);
    // carro2.scale(5, 0.15, 3);
    // carro2.model();

    for(int i = 0; i < MAX; i++){
        rua[i].position(0, -5, -5 * i);
        rua[i].scale(5, 0.15, 2);
        rua[i].model();
    }
}

void update()
{
    x += 0.15;
}