#include <stdlib.h>
#include <GL/glut.h>

// Ball position
float ballX = -0.8f;
float ballY = 0.0f;
float ballZ = -1.0f;

// Ball movement flags and variables
float ballXSpeed = 0.01f;
float ballYSpeed = 0.01f;
float gravity = -0.0005f;
float bounceFactor = -0.8f; // Ball loses some velocity on bounce
float floorLevel = -0.5f;  // Floor level for bounce

void drawBall(void) {
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(ballX, ballY, ballZ);
    glutSolidSphere(0.1, 50, 50); // Ball with radius 0.1
}

// Key press handler for manual movement
void keyPress(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        ballY += 0.05f;
    if (key == GLUT_KEY_DOWN)
        ballY -= 0.05f;
    if (key == GLUT_KEY_LEFT)
        ballX -= 0.05f;
    if (key == GLUT_KEY_RIGHT)
        ballX += 0.05f;
    glutPostRedisplay();
}

// Rendering setup
void initRendering() {
    glEnable(GL_DEPTH_TEST);
}

// Draw the scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawBall();
    glutSwapBuffers();
}

// Timer function to update ball position
void update(int value) {
    // Update ball's vertical position
    ballY += ballYSpeed;
    ballYSpeed += gravity; // Apply gravity

    // Bounce on floor
    if (ballY <= floorLevel) {
        ballY = floorLevel;
        ballYSpeed *= bounceFactor; // Reverse direction with reduced speed
    }

    // Update ball's horizontal position (for side-to-side movement)
    ballX += ballXSpeed;

    // Reverse direction when hitting walls
    if (ballX >= 0.9f || ballX <= -0.9f) {
        ballXSpeed = -ballXSpeed;
    }

    glutPostRedisplay(); // Redraw scene
    glutTimerFunc(16, update, 0); // 16 ms for ~60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bouncing Ball");
    initRendering();
    glutDisplayFunc(drawScene);
    glutSpecialFunc(keyPress); // Handle arrow key input
    glutTimerFunc(16, update, 0); // Start update loop
    glutMainLoop();
    return 0;
}
