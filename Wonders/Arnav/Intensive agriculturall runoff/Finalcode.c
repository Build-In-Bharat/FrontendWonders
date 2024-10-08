#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>
#define PI 3.14159265359
void drawCircle(float cx, float cy, float radius, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; ++i) {
        float theta = 2.0f * PI * ((float)i / (float)num_segments);
        float x = cx + radius * cos(theta);
        float y = cy + radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}
void drawSemicircle(float cx, float cy, float radius, int num_segments) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= num_segments; ++i) {
        float theta = PI * ((float)i / (float)num_segments);
        float x = cx + radius * cos(theta);
        float y = cy + radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawArrow(float x1, float y1, float x2, float y2) {
    // Draw line
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    // Calculate angle of the line
    float angle = atan2(y2 - y1, x2 - x1);

    // Draw arrowhead
    glBegin(GL_TRIANGLES);
    glVertex2f(x2, y2);
    glVertex2f(x2 - 0.02f * cos(angle - PI / 6), y2 - 0.02f * sin(angle - PI / 6));
    glVertex2f(x2 - 0.02f * cos(angle + PI / 6), y2 - 0.02f * sin(angle + PI / 6));
    glEnd();
}

void displayText(void *font, const char *text, float x, float y) {
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(font, text[i]);
    }
}

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw circles
    glColor3f(1.00f, 1.0f, 1.00f); // Set color to white

    // Draw self-loop over q0
    drawSemicircle(-0.80f, 0.89f, 0.06f, 30);
    glColor3f(0.0f, 0.0f, 1.0f); 
    displayText(GLUT_BITMAP_HELVETICA_10, "U --> U, R", -0.85f, 0.95f);
    // q0 circle 
    glColor3f(1.0f, 1.0f, 1.0f); 
    drawCircle(-0.8f, 0.8f, 0.1f, 800);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    displayText(GLUT_BITMAP_HELVETICA_18, "q0", -0.84f, 0.75f);
    glColor3f(1.0f, 1.0f, 1.0f); // Reset color to white

    // Draw self-loop over q1
    drawSemicircle(-0.3f, 0.89f, 0.06f, 30);
     glColor3f(0.0f, 0.0f, 1.0f); // Reset color to white
    displayText(GLUT_BITMAP_HELVETICA_10, "Phos --> Phos,R | Nitro --> Nitro ,R", -0.4f, 0.95);
    displayText(GLUT_BITMAP_HELVETICA_10, "", -0.25f, -0.06f);
     displayText(GLUT_BITMAP_HELVETICA_10, "Res --> Res,R | Pest --> Pest ,R", -0.4f, 0.90f);
    displayText(GLUT_BITMAP_HELVETICA_10, "O2 --> O2 ,R", -0.20f, 0.85f);
    // q1 circle (previously q4)
     glColor3f(1.0f, 1.0f, 1.0f); // Reset color to white
    drawCircle(-0.3f, 0.8f, 0.1f, 300);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    displayText(GLUT_BITMAP_HELVETICA_18, "q1", -0.34f, 0.75f);
   
   glColor3f(1.0f, 1.0f, 1.0f); 
    // Draw self-loop over q2
     drawSemicircle(0.29f, 0.89f, 0.06f, 30);
     glColor3f(0.0f, 0.0f, 1.0f);
     displayText(GLUT_BITMAP_HELVETICA_10, "Phos --> Phos,R", 0.42f, 0.95);
     displayText(GLUT_BITMAP_HELVETICA_10, "Res --> Res,R ", 0.42f, 0.90f);
     displayText(GLUT_BITMAP_HELVETICA_10, "Pest --> Pest ,R", 0.42f, 0.85f);
    displayText(GLUT_BITMAP_HELVETICA_10, "Nitro --> Nitro ,R", 0.42f, 0.80f);
    displayText(GLUT_BITMAP_HELVETICA_10, "O2 --> X ,R", 0.42f, 0.75f);
 glColor3f(1.0f, 1.0f, 1.0f); // Reset color to white
    // q2 circle (previously q3)
    drawCircle(0.3f, 0.8f, 0.1f, 30);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    displayText(GLUT_BITMAP_HELVETICA_18, "q2", 0.26f, 0.75f);
    glColor3f(1.0f, 1.0f, 1.0f); // Reset color to white

    // q3 circle
    drawCircle(-0.3f, 0.4f, 0.1f, 30); // Moved below q4
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    displayText(GLUT_BITMAP_HELVETICA_18, "q3", -0.34f, 0.35f);
    glColor3f(1.0f, 1.0f, 1.0f); // Reset color to white

    // q4 circle (previously q1)
    drawCircle(0.3f, 0.4f, 0.1f, 30); // Moved below q1
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    displayText(GLUT_BITMAP_HELVETICA_18, "q4", 0.26f, 0.35f);
    glColor3f(1.0f, 1.0f, 1.0f); // Reset color to white
    // q6 circle (previously q0)
    drawCircle(-0.8f, 0.01f, 0.1f, 30); // Moved below q0
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    displayText(GLUT_BITMAP_HELVETICA_18, "q6", -0.84f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // Reset color to white

    // q5 circle 
    drawCircle(-0.3f, -0.25f, 0.1f, 30); // Moved below q1
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    displayText(GLUT_BITMAP_HELVETICA_18, "q5", -0.34f, -0.20f);
    glColor3f(1.0f, 1.0f, 1.0f); // Reset color to white
    // Draw lines for transitions with arrowheads
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    glLineWidth(2.0f);
    //initial input line
     drawArrow(-1.0f, 0.79f, -0.91f, 0.79f);
    // q0 to q1
    drawArrow(-0.85f, 0.79f, -0.41f, 0.79f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    displayText(GLUT_BITMAP_HELVETICA_10, "S --> S, R", -0.6f, 0.81f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    // q1 to q2
    drawArrow(-0.35f, 0.79f, 0.19f, 0.79f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    displayText(GLUT_BITMAP_HELVETICA_10, "U --> U, L", -0.05f, 0.81f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    // q2 to q3 
    drawArrow(0.25f, 0.79f, -0.23f, 0.49f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    displayText(GLUT_BITMAP_HELVETICA_10, "U --> U, R", -0.15f, 0.63f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    // q3 to q4 
    drawArrow(-0.35f, 0.39f,0.19f, 0.39f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    displayText(GLUT_BITMAP_HELVETICA_10, "X --> X, R", 0.0f, 0.41f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    // q1 to q6
    drawArrow( -0.34f, 0.79f,-0.76f, 0.13f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    displayText(GLUT_BITMAP_HELVETICA_10, "C --> C, R", -0.75f, 0.42f);
    displayText(GLUT_BITMAP_HELVETICA_10, "U --> U, R", -0.75f, 0.48f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    // q4 to q5 
    drawArrow( 0.26f, 0.39f,-0.2f, -0.19f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    displayText(GLUT_BITMAP_HELVETICA_10, "Phos --> Phos ,R", -0.05f, 0.0f);
    displayText(GLUT_BITMAP_HELVETICA_10, "Nitro --> Nitro ,R", -0.05f, -0.06f);
     displayText(GLUT_BITMAP_HELVETICA_10, "Res --> Res ,R", -0.05f, -0.12f);
    displayText(GLUT_BITMAP_HELVETICA_10, "Pest --> Pest ,R", -0.05f, -0.18f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    // q4 to q6 
    drawArrow( 0.26f, 0.39,-0.73f, 0.13f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    displayText(GLUT_BITMAP_HELVETICA_10, "X --> X, R", -0.60f, 0.11f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    // q3 to q5 
    drawArrow(-0.34f, 0.39f, -0.34f, -0.14f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    displayText(GLUT_BITMAP_HELVETICA_10, "Phos --> Phos ,R", -0.30f, 0.04f);
    displayText(GLUT_BITMAP_HELVETICA_10, "Nitro --> Nitro ,R", -0.30f, 0.10f);
     displayText(GLUT_BITMAP_HELVETICA_10, "Res --> Res ,R", -0.30f, 0.22f);
    displayText(GLUT_BITMAP_HELVETICA_10, "Pest --> Pest ,R", -0.30f, 0.16f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    displayText(GLUT_BITMAP_HELVETICA_18, "Text in blue represent self loop transition", 0.1f, -0.71f);
displayText(GLUT_BITMAP_HELVETICA_18, "Text in green represent state change transition", 0.1f, -0.63f);
    displayText(GLUT_BITMAP_HELVETICA_18, "Text in red represent state name", 0.15f, -0.55f);
    glutSwapBuffers();}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(850, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Turing Machine Diagram");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;}




























