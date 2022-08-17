#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"
#include <time.h>

extern bool gameOver;

bool food = true;
int foodX, foodY;
int gridX, gridY;
short snakeDirection = RIGHT;

// TAMANHO E PARTES DA COBRA
int snakeLength = 5;
int posX[snakeMax] = {20, 20, 20, 20, 20}, posY[snakeMax] = {20, 19, 18, 17, 16};

void unit(int x, int y);

// CRIAR O GRID
void initGrid(int x, int y)
{
    gridX = x;
    gridY = y;
}

void drawGrid()
{
    for(int x = 0; x < gridX; x++){
        for(int y = 0; y < gridY; y++){
            // COLOCAR A COR DA BORDA DO GRID
            if(x == 0 || y == 0 || x == gridX-1 || y == gridY-1){
                glLineWidth(1.5);
                glColor4f(1.0, 0.0, 0.0, 0.5);
            }
            else{
                glLineWidth(1.0);
                glColor4f(1.0, 1.0, 1.0, 0.1);
            }
            unit(x, y);
        }
    }
}

// DESENHAR UMA UNIDADE DA LINHA DO GRID
void unit(int x, int y)
{
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + 1, y);
        glVertex2f(x + 1, y + 1);
        glVertex2f(x, y + 1);
    glEnd();
}

// DESENHAR A COMIDA NO MAPA
void drawFood()
{
    if(food){
        foodX = random(1, gridX - 2);
        foodY = random(1, gridY - 2);
    }
    food = false;
    
    glColor3f(1.0, 0.0, 0.0);
    glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

// DESENHA A COBRA NO MAPA
void drawSnake()
{
    // SETA A POSICAO DAS PARTES DA COBRA
    for(int i = snakeLength - 1; i > 0; i--){
        posX[i] = posX[i -1];
        posY[i] = posY[i -1];
    }
    
    // SELECIONA A DIRECAO QUE VAI DESENHAR
    if(snakeDirection == UP)
        posY[0]++;
    if(snakeDirection == DOWN)
        posY[0]--;
    if(snakeDirection == LEFT)
        posX[0]--;
    if(snakeDirection == RIGHT)
        posX[0]++;

    for(int i = 0; i < snakeLength; i++){
        // COR DA COBRA
        if(i == 0)
            glColor3f(0.0, 1.0, 0.0);
        else
            glColor3f(0.0, 0.5, 0.0);
        // DESENHAR A COBRA
        glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
    }

    //PEGAR A COMIDA
    if(posX[0] == foodX && posY[0] == foodY){
        food = true;
        if(snakeLength < snakeMax)
            snakeLength ++;
    }

    // CASO CHEGUE AO EXTREMO DA TELA DECLARAR GAMEOVER
    if(posX[0] == 0 || posX[0] == gridX - 1 || posY[0] == 0 || posY[0] == gridY - 1){
        gameOver = true;
    }   

    //CASO A COBRA COLIDA NELA MESMA
    for(int i = 1; i < snakeLength; i ++) {
        if(posX[0] == posX[i] && posY[0] == posY[i]){
            gameOver = true;
        }
    }
}

int random(int min, int max)
{
    srand(time(NULL));
    return min + rand() % (max - min);
}