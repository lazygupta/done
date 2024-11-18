
#include<GL/glut.h>

float r = 100.0, xi = 0.0, yi = 0.0;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200.0, 200.0, -300.0, 300.0);
}

void draw() {
float xk = 0.0, yk = r;
float pk = 1.0 - r;

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POINTS);

glVertex2f(xi, yi + r);
    glVertex2f(xi, yi - r);
    glVertex2f(xi + r, yi);
    glVertex2f(xi - r, yi);

    while (xk <= yk) {
        if (pk < 0) {
            pk += (2.0 * xk) + 3.0;
        } else {
            yk -= 1.0;
            pk += (2.0 * xk) - (2.0 * yk) + 5.0;
        }
        xk += 1.0;

        // Plot all eight symmetric points
        glVertex2f(xi + xk, yi + yk); // Octant 1
        glVertex2f(xi - xk, yi + yk); // Octant 2
        glVertex2f(xi + xk, yi - yk); // Octant 3
        glVertex2f(xi - xk, yi - yk); // Octant 4
        glVertex2f(xi + yk, yi + xk); // Octant 5
        glVertex2f(xi - yk, yi + xk); // Octant 6
        glVertex2f(xi + yk, yi - xk); // Octant 7
        glVertex2f(xi - yk, yi - xk); // Octant 8
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(400, 600);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();

}