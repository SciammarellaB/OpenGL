#include "main.h"

#define FPS 60

float cubeRot = 0;

void init();
void display();
void reshape(int, int);
void timer(int);
void movement();

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                              //INICIALIZADOR DA BIBLIOTECA
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);        //PADRAO CASO N SEJA INFORMADO - INFORMA O TIPO DE CORES QUE SERÃO UTILIZADAS - BUFFER DUPLO DO DISPLAY
    
    glutInitWindowSize(640, 640);                       //TAMANHO DA JANELA
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH_MM)) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 500) / 2);   //POSICAO DA JANELA QUANDO EXECUTAR

    glutCreateWindow("Cubo que roda");                  //TITULO DO PROGRAMA
    
    glutDisplayFunc(display);                           //CALLBACK DA JANELA

    glutReshapeFunc(reshape);               

    glutTimerFunc(0, timer, 0);                         //FUNCAO PARA CRIAR O LOOP

    init(); 

    glutMainLoop();                                     //LOOP PARA PROCESSAMENTO
    return 0;
}

void init(){

    glClearColor(0, 0.0, 0.0, 1.0);                     //INICIA A COR DE FUNDO DA TELA PARA PRETO
    glEnable(GL_DEPTH_TEST);      //TESTA PROFUNCIDADE PARA RENDERIZAR AS FACES DO OBJETO FAZENDO A FACE DA FRENTE SEMPRE APARECER
}

//TELA
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //RESET DO FRAME
    glLoadIdentity();                                   //RESET DE TRANSFORMS DO FRAME

    //POSICAO ESCALA ROTACAO INICIAL
    glTranslatef(0.0, 0.0, -5.0);
    glScalef(1.0, 1.0, 1.0);
    glRotatef(cubeRot,1,1,0);
    glRotatef(-cubeRot,0,0,1);

    #pragma region DESENHAR_COISAS
    cubo();
    #pragma endregion

    glutSwapBuffers();
}

void reshape(int width, int height)                     //CHAMADO QUANDO ALTERA A JANELA - MINIMIZAR, MAXIMIZAR e APARECER NOVAMENTE
{
    glViewport(0,0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 2.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int)                                         //FUNCAO RECURSIVA PARA CHAMAR A ATUALIZACAO
{
    glutPostRedisplay();
    srand(time(NULL));
    glutTimerFunc(1000/FPS, timer, 0);

    cubeRot ++;

    if(cubeRot > 360)
        cubeRot = 0;
}