#include <GL/gl.h>
#include <GL/glut.h>

void init();
void displayConfig();
void displayCallback();
void displayReshapeCallback(int w, int h);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);      //INICIALIZAR O GLUT CHAMAR ANTES DE QUALQUER COISA DO GLUT

    displayConfig();            

    glutDisplayFunc(displayCallback);

    glutReshapeFunc(displayReshapeCallback);
    
    init();

    glutMainLoop();             //LOOP DE PROCESSAMENTO DO GLUT

    return 0;
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);   //COR INICIAL DO FUNDO DE TELA
}

//CONFIGURACOES DA TELA
void displayConfig(){
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Snake - The Game");
}

void displayCallback(){
    glClear(GL_COLOR_BUFFER_BIT);   //LIMPA O BUFFER DE COR TODA VEZ QUE A TELA FOR CARREGADA
    glutSwapBuffers();              //CARREGA O PROXIMO FRAME DA TELA
}

void displayReshapeCallback(int w, int h){
    //CORRECAO PARA CASO A TELA SEJA REDIMENSIONADA
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);       //TAMANHO TOTAL DA TELA - INICIO NO 0,0 TERMINO NO W,H
    glMatrixMode(GL_PROJECTION);                    //ALTERACAO DE PROJECAO DA MATRIZ DE TELA
    glLoadIdentity();
    glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);       //ACERTO DE METRICAS DE PROJECAO
    glMatrixMode(GL_MODELVIEW_MATRIX);
}