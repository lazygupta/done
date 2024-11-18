#include<stdlib.h> 
#include<GL/glut.h> 
float boatX = 0.0f;
float boatY = 0.0f;
float boatZ = -1.0f;
int moveRight = 1;

void init() {
    glEnable(GL_DEPTH_TEST);
}

void water() {
    float x1 = -0.9, x2 = -0.85, y = -0.1;
    int i, j;
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    for (i = 0;i < 50;i++) {
        for (j = 0;j < 20;j++) {
            glVertex2f(x1, y);
            glVertex2f(x2, y);
            x1 += 0.09;
            x2 += 0.09;
        }
        y -= 0.02;
        x1 = -0.9;
        x2 = -0.85;
    }
    glEnd();
    glFlush();
}

void boat() {
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(boatX, boatY, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.1);
    glVertex2f(0.25, 0.1);
    glVertex2f(0.2, 0.0);
    glVertex2f(0.05, 0.0);
    glEnd();
    glFlush();
    // mans body line
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.075, 0.15);
    glVertex2f(0.075, 0.1);
    //stick
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.2, 0.14);
    glVertex2f(0.0, -0.1);
    glEnd();
    glFlush();
    // man's head
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.075, 0.175, 0.0);
    glutSolidSphere(0.02, 100, 10);
    glEnd();
    glFlush();
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    water();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    boat();

    glutSwapBuffers();
}

void update(int value) {
    if (moveRight) {
        boatX += 0.005f; // Move right
        if (boatX > 1.0f)
            moveRight = 0; // Change direction to left
    } else {
        boatX -= 0.005f; // Move left
        if (boatX < -1.0f)
            moveRight = 1; // Change direction to right
    }

    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(25, update, 0); // Call update every 16 ms (~60 FPS)
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("BOAT");
    init();
    glutDisplayFunc(draw);
    glutTimerFunc(16, update, 0); 
    glutMainLoop();
    return(0);
}
