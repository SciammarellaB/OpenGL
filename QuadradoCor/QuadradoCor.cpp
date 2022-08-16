#include <GL/glut.h>

//FORMA
void square(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
        //RESET COLOR
        glClearColor(0.0, 0.0, 0.0, 1.0);
        //COR       - RGB - COR PARA O VERTICE ABAIXO
        //VERTICE   -
        //V1
        glColor3f(0.0, 255.0, 0.0);
        glVertex2f(-0.5, 0.5);
        //V2
        glColor3f(0.0, 0.0, 120.0);
        glVertex2f(0.5, 0.5);
        //V3
        glColor3f(0.0, 255.0, 58.0);
        glVertex2f(0.5, -0.5);
        //V4
        glColor3f(150.0, 255.0, 0.0);
        glVertex2f(-0.5, -0.5);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);              //INICIALIZADOR DA BIBLIOTECA
    glutInitDisplayMode(GLUT_RGB);      //PADRAO CASO N SEJA INFORMADO

    glutInitWindowSize(500, 500);       //TAMANHO DA JANELA
    glutInitWindowPosition(100, 100);   //POSICAO DA JANELA QUANDO EXECUTAR

    glutCreateWindow("Quadrado - Cor"); //TITULO DO PROGRAMA
    
    glutDisplayFunc(square);            //CALLBACK DA JANELA

    glutMainLoop();                     //LOOP PARA PROCESSAMENTO
    return 0;
}