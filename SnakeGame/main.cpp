#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

#define COLUMN 40
#define ROW 40
#define FPS 10

extern short snakeDirection;

bool gameOver = false;

void init();
void timerCallback(int);
void displayConfig();
void displayCallback();
void displayReshapeCallback(int w, int h);
void keyboardCallback(int, int, int);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);      //INICIALIZAR O GLUT CHAMAR ANTES DE QUALQUER COISA DO GLUT
    displayConfig();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glutDisplayFunc(displayCallback);
    glutReshapeFunc(displayReshapeCallback);
    glutTimerFunc(0, timerCallback, 0);
    glutSpecialFunc(keyboardCallback);    
    init();
    glutMainLoop();             //LOOP DE PROCESSAMENTO DO GLUT
    return 0;
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);   //COR INICIAL DO FUNDO DE TELA
    initGrid(COLUMN, ROW);             //CHAMA FUNCAO DO ARQUIVO "game.cpp" PARA INICIALIZAR O GRID
}

void timerCallback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timerCallback, 0);
}

void keyboardCallback(int key, int x, int y)
{
    switch(key){
        case GLUT_KEY_UP:
            if(snakeDirection != DOWN){
                snakeDirection = UP;
            }
            break;
        case GLUT_KEY_DOWN:
            if(snakeDirection != UP){
                snakeDirection = DOWN;
            }
            break;
        case GLUT_KEY_LEFT:
            if(snakeDirection != RIGHT){
                snakeDirection = LEFT;
            }
            break;
        case GLUT_KEY_RIGHT:
            if(snakeDirection != LEFT){
                snakeDirection = RIGHT;
            }
            break;
    }
}

//CONFIGURACOES DA TELA
void displayConfig()
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Snake - The Game");
}

void displayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT);   //LIMPA O BUFFER DE COR TODA VEZ QUE A TELA FOR CARREGADA
    drawGrid();                     //DESENHA O GRID NA TELA
    drawSnake();                    //DESENHA A COBRA
    drawFood();                     //DESENHA A COMIDA
    glutSwapBuffers();              //CARREGA O PROXIMO FRAME DA TELA
    
    if(gameOver){
        //DESCOBRIR COMO ABRIR UM DIALOGO DIZENDO QUE ACABOU O JOGO
        exit(0);
    }
}

void displayReshapeCallback(int w, int h)
{
    //CORRECAO PARA CASO A TELA SEJA REDIMENSIONADA
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);       //TAMANHO TOTAL DA TELA - INICIO NO 0,0 TERMINO NO W,H
    glMatrixMode(GL_PROJECTION);                    //ALTERACAO DE PROJECAO DA MATRIZ DE TELA
    glLoadIdentity();
    glOrtho(0.0, COLUMN, 0.0, ROW, -1.0, 1.0);       //ACERTO DE METRICAS DE PROJECAO
    glMatrixMode(GL_MODELVIEW_MATRIX);
}