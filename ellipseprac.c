#include<GL/glut.h>

float a = 100, b = 50, xc = 320, yc = 240;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void draw() {
    float bb = b * b;
    float aa = a * a;
    float p1k, p2k;
    float x = 0.0, y = b;
    p1k = bb - aa * b + (1.0 / 4) * aa;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

    while ((2 * bb * x) < (2 * aa * y)) {
        if (p1k < 0) {
            x++;
            p1k += (2 * bb * x) + bb;
        }
        else {
            x++;
            y--;
            p1k += (2 * bb * x) + bb - (2 * aa * y);
        }
        glVertex2f(xc + x, yc + y);
        glVertex2f(xc - x, yc + y);
        glVertex2f(xc + x, yc - y);
        glVertex2f(xc - x, yc - y);
    }

    p2k = (bb * (x + 0.5) * (x + 0.5)) + (aa * (y - 1) * (y - 1)) - (aa * bb);

    while (y >= 0) {
        if (p2k > 0) {
            y--;
            p2k -= (2 * aa * y) + aa;
        }
        else {
            x++;
            y--;
            p2k += (2 * bb * x) + aa - (2 * aa * y);
        }
        glVertex2f(xc + x, yc + y);
        glVertex2f(xc - x, yc + y);
        glVertex2f(xc + x, yc - y);
        glVertex2f(xc - x, yc - y);
    }

    glEnd();
    glFlush();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Ellipse");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}