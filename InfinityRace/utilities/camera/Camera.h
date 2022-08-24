#pragma once
#include <glm/glm.hpp>
#include <GL/glut.h>


class Camera {
public:
    
    void config(float fov, float ratio, float near, float far){
        gluPerspective(fov, ratio, near, far);
    }

    void startPosition(glm::vec3 position){
        this->position = position;
        change();
    }

    void startLook(glm::vec3 viewDirection){
        this->viewDirection = viewDirection;
        change();
    }

private:
    glm::vec3 position = {0.0f, 0.0f, 0.0f}, 
        viewDirection = {0.0f, 0.0f, 0.0f}, 
        up = {0.0f, 1.0f, 0.0f};

    void change(){
        gluLookAt(this->position.x, this->position.y, this->position.z, 
            this->viewDirection.x, this->viewDirection.y, this->viewDirection.z, 
            this->up.x, this->up.y, this->up.z);
    }
};