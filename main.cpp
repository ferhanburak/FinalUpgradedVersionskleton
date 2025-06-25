#include <GL/glut.h>
#include "Game.h"

Game game;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    game.render();
    glutSwapBuffers();
}

void specialKeys(int key, int, int) {
    game.handleKeyPress(key, 0.3f);
    glutPostRedisplay();
}

void mouse(int button, int state, int, int) {
    if (button == GLUT_LEFT_BUTTON) {
        game.setShooting(state == GLUT_DOWN);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D Shooting Game");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);
    game.init();
    game.onTimer();

    glutMainLoop();
    return 0;
}
