#include<GL/glut.h>

float carX = -0.5f;
float carY = -0.5f;
float carZ = 0.0f;

int flag = 1;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Drawing a Car and Wheels
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(carX, carY, carZ);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0); // Bottom-left
    glVertex2f(-0.5, 0.2); // Top-left
    glVertex2f(-0.3, 0.2); // Next point on the roof
    glVertex2f(-0.1, 0.5); // Peak of the roof
    glVertex2f(0.1, 0.5);  // Peak of the roof on the other side
    glVertex2f(0.3, 0.2);  // Right side of the roof
    glVertex2f(0.5, 0.2);  // Top-right
    glVertex2f(0.5, 0);    // Bottom-right
    glEnd();
    glFlush();

    // Wheels
    glTranslatef(-0.3, 0.0, 0.0);
    glutSolidSphere(0.1, 100, 10);

    glTranslatef(0.5, 0.0, 0.0);
    glutSolidSphere(0.1, 100, 10);
    

    glutSwapBuffers();
}

void updater(int value) {
    if (flag == 1) {
        carX += 0.004f;
        if (carX > 1.5) {
            flag = 0;
        }
    }

    glutPostRedisplay();

    glutTimerFunc(1, updater, 5000);
}

void keyPress(int key, int x, int y) {
    // Adjust car's position based on arrow key pressed
    if (key == GLUT_KEY_UP)     // Move up
        carY += 0.05f;
    if (key == GLUT_KEY_DOWN)   // Move down
        carY -= 0.05f;
    if (key == GLUT_KEY_LEFT)   // Move left
        carX -= 0.05f;
    if (key == GLUT_KEY_RIGHT)  // Move right
        carX += 0.05f;

    // Request a redraw after position changes
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Moving Car");
glutSpecialFunc(keyPress);
    init();

    glutDisplayFunc(draw);
    glutTimerFunc(1, updater, 5000);
    glutMainLoop();
}