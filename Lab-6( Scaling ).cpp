#include <glut.h>
#include <iostream>
#include <cmath>

int n;
int x[100], y[100];
float sfx, sfy;

void draw();
void scale(int, int);

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    draw();

    scale(x[0], y[0]);

    glColor3f(1.0, 1.0, 0.0);
    draw();

    glFlush();
}

void draw() {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++) {
        glVertex2i(x[i], y[i]);
    }
    glEnd();
}

void scale(int centerX, int centerY) {
    for (int i = 0; i < n; i++) {
        x[i] = centerX + static_cast<int>((x[i] - centerX) * sfx);
        y[i] = centerY + static_cast<int>((y[i] - centerY) * sfy);
    }
}

int main(int argc, char** argv) {
    std::cout << "Enter no. of sides in polygon: ";
    std::cin >> n;

    std::cout << "Enter coordinates x, y for each vertex: ";
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::cout << "Enter scale factors: sfx and sfy : ";
    std::cin >> sfx >> sfy;

    glutInit(&argc, argv);
    glutCreateWindow("Polygon Scaling");
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    gluOrtho2D(0, 500, 0, 500);

    glutMainLoop();

    return 0;
}
