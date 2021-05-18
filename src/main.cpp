#include "../include/GL/glut.h"
#include "../include/GL/freeglut.h"

#include "../include/settings.hpp"
#include "../include/functions.hpp"

using namespace settings;
using namespace functions;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - quad)/2,
                           (GetSystemMetrics(SM_CYSCREEN) - quad)/2);
    glutInitWindowSize(quad, quad);
    glutCreateWindow("Snake");

    init(back, col);

    glutDisplayFunc(display);
    glutTimerFunc(seconds, time, 0.0);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(Special);

    glFlush();

    glutMainLoop();
    glutLeaveMainLoop();
}