#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

GLint WINDOW_WIDTH  = 500,
      WINDOW_HEIGHT = 500;

void init();
void draw();

bool wbgc = true;

void keyboard(GLubyte key, GLint x, GLint y);

//=================================================================================================

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  GLint screen_width  = glutGet(GLUT_SCREEN_WIDTH),
        screen_height = glutGet(GLUT_SCREEN_HEIGHT);

  glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_WIDTH);
  glutCreateWindow("OpenGL Exercicio 1");

  init();

  glutDisplayFunc(draw);
  glutKeyboardFunc(keyboard);

  glutMainLoop();

  return EXIT_SUCCESS;
}

void init()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}


void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhar o corpo da casa (quadrado)
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.200);
    glVertex2f(-0.5, 0.200);
    glEnd();

    // Desenhar o telhado da casa (triângulo)
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, 0.2);
    glVertex2f(0.0, 0.6);
    glVertex2f(0.5, 0.2);
    glEnd();

    // Desenhar a porta da casa (quadrado)
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.1, -0.480);
    glVertex2f(0.1, -0.480);
    glVertex2f(0.1, 0.0);
    glVertex2f(-0.1, 0.0);
    glEnd();

    // Desenhar a janela da casa (quadrado)
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.290, -0.090);
    glVertex2f(0.170, -0.090);
    glVertex2f(0.170, 0.0);
    glVertex2f(0.290, 0.0);
    glEnd();

    // Desenhar a janela da casa (quadrado)
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.430, -0.090);
    glVertex2f(0.300, -0.090);
    glVertex2f(0.300, 0.0);
    glVertex2f(0.430, 0.0);
    glEnd();

    // Desenhar a janela da casa (quadrado)
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.290, -0.100);
    glVertex2f(0.170, -0.100);
    glVertex2f(0.170, -0.2);
    glVertex2f(0.290, -0.2);
    glEnd();

    // Desenhar a janela da casa (quadrado)
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.430, -0.100);
    glVertex2f(0.300, -0.100);
    glVertex2f(0.300, -0.2);
    glVertex2f(0.430, -0.2);
    glEnd();

    glFlush();
}

void keyboard(GLubyte key, GLint x, GLint y)
{
  if (key == 32)
      if (wbgc) {
          glClearColor(0.0, 0.0, 0.0, 1.0);
          draw();
        }
      else {
          glClearColor(1.0, 1.0, 1.0, 1.0);
          draw();
      }
      wbgc = !wbgc;
}




