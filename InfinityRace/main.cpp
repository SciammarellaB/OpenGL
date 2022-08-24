#include "main.h"

#define FPS 60

Camera cam;

void init();
void display();
void reshape(int, int);
void timer(int);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Infinity Race");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    return 0;
}

void init()
{
    setup();
    glEnable(GL_CULL_FACE | GL_DEPTH_TEST);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    #pragma region GAME
    game();
    #pragma endregion

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0,0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //START CAMERA
    cam.config(60.0, 1.0, 2.0, 1000.0);
    cam.startPosition({0.0f, 2.0f, 15.0f});
    glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
    glutPostRedisplay();
    srand(time(NULL));
    glutTimerFunc(1000/FPS, timer, 0);

    update();
}