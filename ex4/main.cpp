﻿// https://cs.lmu.edu/~ray/notes/openglexamples/
// g++ litsolids.cpp -lX11 -lGL -lGLU -lglut -g -Wall -O2 -o r.exe
//
// This program shows three cyan objects illuminated with a single yellow
// light source.  It illustrates several of the lighting parameters.

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void drawWheel() {

    // Draw Tire
    glRotatef(0.0, 1.0, 0.0, 0.0);
    glutSolidTorus(0.120, 0.450, 16, 40);

    // Draw ball
    glutSolidSphere(0.1, 20, 20);

    // Draw spokes
    glPushMatrix();
    glScalef(0.1, 1.4, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    // Draw spokes
    glPushMatrix();
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glScalef(0.1, 1.4, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    // Draw spokes
    glPushMatrix();
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(0.1, 1.4, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    // Draw spokes
    glPushMatrix();
    glRotatef(135.0, 0.0, 0.0, 1.0);
    glScalef(0.1, 1.4, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();
}

void drawShape(){
    glScalef(1.0, 0.1, 0.1);
    glutSolidCube(1.0);
//
//    // Draw table legs
//    glPushMatrix();
//    glColor3f(1.0, 0.0, 0.0);
//    glTranslatef(0.9, 0.7, 0.4);
//    glScalef(0.2, 1.4, 0.1);
//    glutSolidCube(1.0);
//    glPopMatrix();
}

// Clears the window and depth buffer and draws three solids.
//
// The solids are placed so that they either sit or float above the x-z plane;
// therefore note one of the first things that is done is to rotate the whole
// scene 20 degrees about x to turn the top of the scene toward the viewer.
// This lets the viewer see how the torus goes around the cone.
void display() {
    glClear(GL_COLOR_BUFFER1_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    //glPushMatrix();

   // glRotatef(0.0, 1.0, 0.0, 0.0);
//    // Make a torus floating 0.5 above the x-z plane.  The standard torus in
//    // the GLUT library is, perhaps surprisingly, a stack of circles which
//    // encircle the z-axis, so we need to rotate it 90 degrees about x to
//    // get it the way we want.
//    glPushMatrix();
//    glTranslatef(-0.75, 0.5, 0.0);
//    glRotatef(90.0, 1.0, 0.0, 0.0);
//    glutSolidTorus(0.275, 0.85, 16, 40);
//    glPopMatrix();
//
//    // Make a cone.  The standard cone "points" along z; we want it pointing
//    // along y, hence the 270 degree rotation about x.
//    glPushMatrix();
//    glTranslatef(-0.75, -0.5, 0.0);
//    glRotatef(270.0, 1.0, 0.0, 0.0);
//    glutSolidCone(1.0, 2.0, 70, 12);
//    glPopMatrix();
//
//    // Add a sphere to the scene.
//    glPushMatrix();
//    glTranslatef(0.75, 0.0, -1.0);
//    glutSolidSphere(1.0, 30, 30);
//    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0, 0.0, 0.0);
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, 0.0, 0.0);
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    glScalef(4.0, 1.0, 1.0);
    drawShape();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, 0.75, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(1.5, 1.0, 1.0);
    drawShape();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 2.0, 0.0);
    glRotatef(-45.0, 0.0, 0.0, 1.0);
    glScalef(1.5, 1.0, 1.0);
    drawShape();
    glPopMatrix();

    glFlush();
}

//PARAMETROS glOrtho
//left, right :Specify the coordinates for the left and right vertical clipping planes.
//bottom, top :Specify the coordinates for the bottom and top horizontal clipping planes.
//nearVal, farVal:Specify the distances to the nearer and farther depth clipping planes. These values are negative if the plane is to be behind the viewer.

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    GLfloat aspect = GLfloat(w) / GLfloat(h);
    glLoadIdentity();

    if (w <= h) {
        // width is smaller, so stretch out the height
        glOrtho(-2.5, 2.5, -2.5/aspect, 2.5/aspect, -10.0, 10.0);
    } else {
        // height is smaller, so stretch out the width
        glOrtho(-2.5*aspect, 2.5*aspect, -2.5, 2.5, -10.0, 10.0);
    }


    //gluPerspective (60,aspect, 0.1, 15);

}

// Performs application specific initialization.  It defines lighting
// parameters for light source GL_LIGHT0: black for ambient, yellow for
// diffuse, white for specular, and makes it a directional source
// shining along <-1, -1, -1>.  It also sets a couple material properties
// to make cyan colored objects with a fairly low shininess value.  Lighting
// and depth buffer hidden surface removal are enabled here.
void init() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    //gluLookAt(0, 2.5, 0, 0,0,0, 0, 0, -1);


    GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
    GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat direction[] = { 0.0, -10.0, 0.0, 1.0 };
    GLfloat direction1[] = { 0.0, 10.0, 0.0, 1.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cyan);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);

    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, yellow);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glLightfv(GL_LIGHT0, GL_POSITION, direction);

    glLightfv(GL_LIGHT1, GL_AMBIENT, black);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);
    glLightfv(GL_LIGHT1, GL_POSITION, direction1);

    glEnable(GL_LIGHTING);                // so the renderer considers light
    glEnable(GL_LIGHT0);                  // turn LIGHT0 on
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);              // so the renderer considers depth

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("The scooter");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
}