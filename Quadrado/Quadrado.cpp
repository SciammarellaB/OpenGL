#include <GL/glut.h>

//FORMA
void quadrado(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
        //V1
        glVertex2f(-0.5, 0.5);
        //V2
        glVertex2f(0.5, 0.5);
        //V3
        glVertex2f(0.5, -0.5);
        //V4
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

    glutCreateWindow("Quadrado");       //TITULO DO PROGRAMA
    
    glutDisplayFunc(quadrado);          //CALLBACK DA JANELA

    glutMainLoop();                     //LOOP PARA PROCESSAMENTO
    return 0;
}