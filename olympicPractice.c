#include <GL/glut.h>

// Function to initialize OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Background color: white
    gluOrtho2D(0, 400, 0, 300);      // Orthogonal projection
     glMatrixMode(GL_PROJECTION);
}

// Function to draw a circle
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    float p = 1 - r;

    glBegin(GL_POINTS);

    while (x <= y) {
        glVertex2f(x + xc, y + yc);
        glVertex2f(y + xc, x + yc);
        glVertex2f(y + xc, -x + yc);
        glVertex2f(x + xc, -y + yc);
        glVertex2f(-x + xc, -y + yc);
        glVertex2f(-y + xc, -x + yc);
        glVertex2f(-x + xc, y + yc);
        glVertex2f(-y + xc, x + yc);

        if (p < 0)
            p += 2 * x + 3;
        else {
           //  y--;
            p += 2 * (x - y) + 3;
            y--;
        }
        x++;
    }

    glEnd();
    glFlush();
}

// Function to display Olympic rings
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

   
    // Draw the Olympic rings
    glColor3f(0.0,0.0,1.0); 
    drawCircle(100, 200, 50);
    glColor3f(0.0,0.0,0.0); // Ring 1
    drawCircle(200, 200, 50);
    glColor3f(1.0,0.0,0.0); // Ring 2
    drawCircle(300, 200, 50);
    glColor3f(1.0,1.0,0.0); // Ring 3
    drawCircle(150, 150, 50);
    glColor3f(0.0,1.0,0.0);// Ring 4
    drawCircle(250, 150, 50); // Ring 5
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Olympic Rings - Same Color");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}