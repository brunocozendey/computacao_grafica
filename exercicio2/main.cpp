#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

GLint WINDOW_WIDTH  = 1024,
WINDOW_HEIGHT = 768;

void init();
void mouse_test(GLint button, GLint action, GLint x, GLint y);
void clear_screen();
void draw(GLint x, GLint y);


//=================================================================================================

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL Exercicio 2");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
  init();
  glutMouseFunc(mouse_test);
  glutMainLoop();


  return EXIT_SUCCESS;
}

void clear_screen(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void init()
{
  glClearColor(255.0, 255.0, 255.0, 1.0);
  clear_screen();
}


void draw(GLint x, GLint y){
    glColor3f(0.0,0.0,0.0);
    glPointSize(50);
    glBegin(GL_POINTS);
    glVertex2f(x , y);
    glEnd();
    glFlush();
}

void mouse_test(GLint button, GLint action, GLint x, GLint y) {
    if (action == GLUT_DOWN) {
        switch (button) {
            case GLUT_LEFT_BUTTON: {
                draw(x,WINDOW_HEIGHT-y);
                break;
            }
            case GLUT_RIGHT_BUTTON: {
                clear_screen();
                break;
            }
            default:
                break;
        }
    }
}






