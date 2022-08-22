#include "main.h"

void camera(float fov, float ratio, float near, float far){
    gluPerspective(fov, ratio, near, far);
}