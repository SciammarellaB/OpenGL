#include "main.h"

#define FPS 60

float cubePosX, cubePosY;
int stateX, stateY;

void init();
void display();
void reshape(int, int);
void timer(int);
void movement();
float random(int min, int max);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                              //INICIALIZADOR DA BIBLIOTECA
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);        //PADRAO CASO N SEJA INFORMADO - INFORMA O TIPO DE CORES QUE SERÃO UTILIZADAS - BUFFER DUPLO DO DISPLAY

    glutInitWindowSize(640, 640);                       //TAMANHO DA JANELA
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH_MM)) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 500) / 2);   //POSICAO DA JANELA QUANDO EXECUTAR

    glutCreateWindow("Quadrado que se mexe");           //TITULO DO PROGRAMA
    
    glutDisplayFunc(display);                           //CALLBACK DA JANELA

    glutReshapeFunc(reshape);               

    glutTimerFunc(0, timer, 0);                         //FUNCAO PARA CRIAR O LOOP

    init(); 

    glutMainLoop();                                     //LOOP PARA PROCESSAMENTO
    return 0;
}

void init(){

    // glClearColor(0, 0.8, 1.0, 1.0);                    //INICIA A COR DE FUNDO DA TELA PARA AZUL
    glClearColor(0, 0.0, 0.0, 1.0);                     //INICIA A COR DE FUNDO DA TELA PARA PRETO

    //INICIALIZAR POSICAO DO CUBO
    cubePosX = -10;
    cubePosY = 0;
}

//TELA
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);                       //RESET DO FRAME
    glLoadIdentity();                                   //RESET DE TRANSFORMS DO FRAME
    
    #pragma region DESENHAR_COISAS
    quadrado(cubePosX, cubePosY);
    #pragma endregion

    glutSwapBuffers();
}

void reshape(int width, int height)                     //CHAMADO QUANDO ALTERA A JANELA - MINIMIZAR, MAXIMIZAR e APARECER NOVAMENTE
{
    glViewport(0,0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int)                                         //FUNCAO RECURSIVA PARA CHAMAR A ATUALIZACAO
{
    glutPostRedisplay();
    srand(time(NULL));
    glutTimerFunc(1000/FPS, timer, 0);

    movement();
}

void movement()
{
    if(cubePosX > 8.0){
        stateX = 1;
        glColor3f((random(0, 255) / 255),(random(0, 255) / 255),(random(0, 255) / 255));
    }
    else if(cubePosX < -10.0){
        stateX = 0;
        glColor3f((random(0, 255) / 255),(random(0, 255) / 255),(random(0, 255) / 255));
    }

    if(cubePosY >= 9){
        stateY = 1;
        glColor3f((random(0, 255) / 255),(random(0, 255) / 255),(random(0, 255) / 255));
    }
    else if(cubePosY <= -9){
        stateY = 0;
        glColor3f((random(0, 255) / 255),(random(0, 255) / 255),(random(0, 255) / 255));
    }

    if(stateX == 0){
        cubePosX += 0.10;
    }
    else{
        cubePosX -= 0.09;
    }

    if(stateY == 0){
        cubePosY += 0.08;
    }
    else{
        cubePosY -= 0.07;
    }
}

float random(int min, int max)
{
    return min + rand() % (max - min);
}