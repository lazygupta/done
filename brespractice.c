#include<GL/glut.h>

float xi = 0.0, yi = 0.0, xf = 120.0, yf = 120.0;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void bres() {
    float dx = xf - xi;
    float dy = yf - yi;


    float X = xi;
    float Y = yi;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

    float pi = (2 * dy) - dx;

    for (float i = 0.0;i < dx; i += 1.0) {
        glVertex2f(X, Y);
        if (pi >= 0) {
            Y += 1.0;
            pi -= dx;
        }
        X += 1.0;
        pi += dy;
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Bresenham Line");
    init();
    glutDisplayFunc(bres);
    glutMainLoop();
}