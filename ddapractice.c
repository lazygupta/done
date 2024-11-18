#include<GL/glut.h>
float xi = 0.0, yi = 0.0, xf = 120.0, yf = 150.0;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void dda() {
    float dx = xf - xi;
    float dy = yf - yi;
    float X = xi, Y = yi;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xinc = dx / steps;
    float yinc = dy / steps;

    for (int i = 0;i < steps; i++) {
        glVertex2f(X, Y);
        X += xinc;
        Y += yinc;
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 400);
    glutCreateWindow("DDA Line Drawing");
    init();
    glutDisplayFunc(dda);
    glutMainLoop();
}
