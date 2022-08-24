#include <GL/glut.h>

class Car {
    public:

    void position(float x, float y, float z){
        this->posX = x;
        this->posY = y;
        this->posZ = z;
    }

    void scale(float scaleX = 1, float scaleY = 1, float scaleZ = 1){
        this->scaleX = scaleX;
        this->scaleY = scaleY;
        this->scaleZ = scaleZ;
    }

    void model(){

        glLoadIdentity();

        glTranslatef(this->posX, this->posY, this->posZ);
        glScalef(this->scaleX, this->scaleY, this->scaleZ);

        glBegin(GL_QUADS);

        //BASE COLOR
        glColor3f(0.5, 0.5, 0.5);

        //3D MESH

        //front
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,1.0,1.0);

        //back
        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);

        //right
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(1.0,1.0,-1.0);

        //left
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(-1.0,1.0,1.0);

        //top
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,1.0,-1.0);
        
        //bottom
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,-1.0);
        
        glEnd();
    }

    private:
    float posX, posY, posZ;
    float scaleX = 1, scaleY = 1, scaleZ = 1;
};