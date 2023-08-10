#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glut.h>

#define BOARD_SIZE 8
#define SQUARE_SIZE 60

int tileColors[BOARD_SIZE][BOARD_SIZE] = {0};

typedef struct {
    float r;
    float g;
    float b;
} Color;

Color colorLookup[3] = {
        {0.0f, 0.0f, 0.0f}, // Black
        {1.0f, 1.0f, 1.0f}, // White
        {0.0f, 1.0f, 0.0f}  // Green
};


void drawCheckerboard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int colorIndex = tileColors[i][j];
            glColor3f(colorLookup[colorIndex].r, colorLookup[colorIndex].g, colorLookup[colorIndex].b);

            glBegin(GL_QUADS);
            glVertex2f(j * SQUARE_SIZE, i * SQUARE_SIZE);
            glVertex2f(j * SQUARE_SIZE + SQUARE_SIZE, i * SQUARE_SIZE);
            glVertex2f(j * SQUARE_SIZE + SQUARE_SIZE, i * SQUARE_SIZE + SQUARE_SIZE);
            glVertex2f(j * SQUARE_SIZE, i * SQUARE_SIZE + SQUARE_SIZE);
            glEnd();
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCheckerboard();
    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, BOARD_SIZE * SQUARE_SIZE, BOARD_SIZE * SQUARE_SIZE, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int row = y / SQUARE_SIZE;
        int col = x / SQUARE_SIZE;
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            tileColors[row][col] = 2; // Toggle the color of the clicked tile
            glutPostRedisplay(); // Trigger a redraw of the scene to update the colors
        }
    }
}

void runOpenGL(int argc, char** argv) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                tileColors[i][j] = 1;
            }
        }
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(BOARD_SIZE * SQUARE_SIZE, BOARD_SIZE * SQUARE_SIZE);
    glutCreateWindow("Tabuleiro");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
}

#endif // RENDERER_H
