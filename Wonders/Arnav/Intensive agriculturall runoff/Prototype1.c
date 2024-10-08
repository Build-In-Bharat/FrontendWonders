#Setup before running code given below
Code given below would run only in linux (Ubuntu)
Before running code we must install freeglut3-dev library of open GL in system
The code given can run in VS code but one needs to download glfw package and glad.
C code for constructing turing machine initial prototype



#include <stdio.h>
#include <GL/freeglut.h>
void displayText(void *font, const char *text, float x, float y) {
  glRasterPos2f(x, y);
  for (int i = 0; text[i] != '\0'; i++) {
    glutBitmapCharacter(font, text[i]);
  }
}
void display() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  // Draw rectangles
  glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
  // q0 rectangle
  glBegin(GL_QUADS);
  glVertex2f(-0.9f, 0.9f);
  glVertex2f(-0.7f, 0.9f);
  glVertex2f(-0.7f, 0.7f);
  glVertex2f(-0.9f, 0.7f);
  glEnd();
  glColor3f(1.0f, 0.0f, 0.0f);
  displayText(GLUT_BITMAP_HELVETICA_18, "q0", -0.89f, 0.85f);
  glColor3f(0.0f, 0.0f, 1.0f);
  displayText(GLUT_BITMAP_HELVETICA_10, "U --> U ,R", -0.89f, 0.94f);
  glColor3f(1.0f, 1.0f, 1.0f);
  // q1 rectangle
  glBegin(GL_QUADS);
  glVertex2f(-0.3f, 0.9f);
  glVertex2f(-0.1f, 0.9f);
  glVertex2f(-0.1f, 0.7f);
  glVertex2f(-0.3f, 0.7f);
  glEnd();
  glColor3f(1.0f, 0.0f, 0.0f);
  displayText(GLUT_BITMAP_HELVETICA_18, "q1", -0.29f, 0.85f);
  glColor3f(0.0f, 0.0f, 1.0f);
  displayText(GLUT_BITMAP_HELVETICA_10, "Res --> Res ,R\n\nPhos --> Phos ,R\n\nNitro --> Nitro ,R\n\nPest --> Pest ,R\n\nO2 --> O2 ,R", -0.59f, 0.94f);
  glColor3f(1.0f, 1.0f, 1.0f);
  // q2 rectangle
  glBegin(GL_QUADS);
  glVertex2f(0.3f, 0.9f);
  glVertex2f(0.5f, 0.9f);
  glVertex2f(0.5f, 0.7f);
  glVertex2f(0.3f, 0.7f);
  glEnd();
  glColor3f(1.0f, 0.0f, 0.0f);
  displayText(GLUT_BITMAP_HELVETICA_18, "q2", 0.31f, 0.85f);
  glColor3f(0.0f, 0.0f, 1.0f);
  displayText(GLUT_BITMAP_HELVETICA_10, "Res --> Res ,L\n\nPhos --> Phos ,L\n\nNitro --> Nitro ,L\n\nPest --> Pest ,L\n\nO2 --> x ,L", 0.29f, 0.94f);
  glColor3f(1.0f, 1.0f, 1.0f);
  // q3 rectangle
  glBegin(GL_QUADS);
  glVertex2f(0.9f, 0.9f);
  glVertex2f(1.1f, 0.9f);
  glVertex2f(1.1f, 0.7f);
  glVertex2f(0.9f, 0.7f);
  glEnd();
  glColor3f(1.0f, 0.0f, 0.0f);
  displayText(GLUT_BITMAP_HELVETICA_18, "q3", 0.85f, 0.85f);
  glColor3f(1.0f, 1.0f, 1.0f);
  // q4 rectangle
  glBegin(GL_QUADS);
  glVertex2f(-0.9f, 0.5f);
  glVertex2f(-0.7f, 0.5f);
  glVertex2f(-0.7f, 0.3f);
  glVertex2f(-0.9f, 0.3f);
  glEnd();
  glColor3f(1.0f, 0.0f, 0.0f);
  displayText(GLUT_BITMAP_HELVETICA_18, "q4", -0.89f, 0.45f);
  glColor3f(1.0f, 1.0f, 1.0f);
  // q5 rectangle
  glBegin(GL_QUADS);
  glVertex2f(-0.3f, 0.5f);
  glVertex2f(-0.1f, 0.5f);
  glVertex2f(-0.1f, 0.3f);
  glVertex2f(-0.3f, 0.3f);
  glEnd();
  glColor3f(1.0f, 0.0f, 0.0f);
  displayText(GLUT_BITMAP_HELVETICA_18, "q5", -0.29f, 0.45f);
  glColor3f(1.0f, 1.0f, 1.0f);
  // q6 rectangle
  glBegin(GL_QUADS);
  glVertex2f(0.3f, 0.5f);
  glVertex2f(0.5f, 0.5f);
  glVertex2f(0.5f, 0.3f);
  glVertex2f(0.3f, 0.3f);
  glEnd();
  glColor3f(1.0f, 0.0f, 0.0f);
  displayText(GLUT_BITMAP_HELVETICA_18, "q6", 0.31f, 0.45f);
  glColor3f(1.0f, 1.0f, 1.0f);
  // Draw lines for transitions
  glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
  glLineWidth(2.0f);
  // q0 to q1
  glBegin(GL_LINES);
  glVertex2f(-0.8f, 0.8f);
  glVertex2f(-0.2f, 0.8f);
  glEnd();
  displayText(GLUT_BITMAP_HELVETICA_10, "S --> S, R", -0.5f, 0.81f);
  // q1 to q2
  glBegin(GL_LINES);
  glVertex2f(-0.1f, 0.8f);
  glVertex2f(0.5f, 0.8f);
  glEnd();
  displayText(GLUT_BITMAP_HELVETICA_10, "U --> U, L", 0.2f, 0.81f);
  // Q1 to Q6
  glBegin(GL_LINES);
  glVertex2f(-0.2f, 0.7f);
  glVertex2f(0.3f, 0.7f);
  glEnd();
  displayText(GLUT_BITMAP_HELVETICA_10, "C --> C, R", 0.05f, 0.71f);
  // q2 to q3
  glBegin(GL_LINES);
  glVertex2f(0.4f, 0.8f);
  glVertex2f(1.0f, 0.8f);
  glEnd();
  displayText(GLUT_BITMAP_HELVETICA_10, "U --> U, R", 0.6f, 0.81f);
  // q3 to q4
  glBegin(GL_LINES);
  glVertex2f(1.0f, 0.8f);
  glVertex2f(-0.8f, 0.5f);
  glEnd();
  displayText(GLUT_BITMAP_HELVETICA_10, "X --> X,R", 0.01f, 0.6f);
  //0.89f, 0.54f
  // q4 to q5
  glBegin(GL_LINES);
  glVertex2f(-0.7f, 0.4f);
  glVertex2f(-0.3f, 0.4f);
  glEnd();
  displayText(GLUT_BITMAP_HELVETICA_10, "X --> X, R", -0.5f, 0.41f);
  // q3 to q5
  glBegin(GL_LINES);
  glVertex2f(1.0f, 0.7f);
  glVertex2f(-0.3f, 0.4f);
  glEnd();
  displayText(GLUT_BITMAP_HELVETICA_10, "Res --> Res ,R\n\nPhos --> Phos ,R\n\nNitro --> Nitro ,R\n\nPest --> Pest ,R", 0.4f, 0.58f);
  // q4 to q6
  glBegin(GL_LINES);
  glVertex2f(-0.7f, 0.4f);
  glVertex2f(0.3f, 0.4f);
  glEnd();
  displayText(GLUT_BITMAP_HELVETICA_10, "Res --> Res ,R\n\nPhos --> Phos ,R\n\nNitro --> Nitro ,R\n\nPest --> Pest ,R", -0.2f, 0.24f);
  glutSwapBuffers();
}
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Turing Machine Diagram");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0; }
