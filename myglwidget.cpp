#include "myglwidget.h"
#include "mainwindow.h"

MyGLWidget::MyGLWidget()
{

}

/* Computergrafik Praktikum
 * Klassisches OpenGL mit freeGLUT
 * FH Aachen, 2017
 */

//#include <GL/glut.h>

#define WINDOW_CAPTION "Computergrafik Praktikum"
#define WINDOW_XPOS 50
#define WINDOW_YPOS 50
#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 480
#define UPDATE_RATE 60


// global variable for engine purposes
// not pretty and hardware-dependent, but gets the job done



// OpenGL settings initialization
void MyGLWidget::initializeGL()
{
    //Tieferpuffer Aktivieren
    glEnable(GL_DEPTH_TEST);
    //welche Seite gezeichnet werden soll
    glEnable(GL_CULL_FACE);
    //vergleich tiefe der pixel mit buffer
    glDepthFunc(GL_LEQUAL);
    //alles gleiche farbe
    glShadeModel(GL_SMOOTH);
    //höchste quali
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    //1.6 wegen FaceCulling nicht zu sehen
    //oder auskommentieren
   // glDisable(GL_CULL_FACE);

    //mit welchem Wert tiefenpuffer gelöscht wird
    glClearDepth(1.0f);
    //hintergrundfarbe
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

/*
// Handler for timer event
void update(int v)
{
    // Schedule a draw event
    glutPostRedisplay();

    // Needs to be registered again
    glutTimerFunc((unsigned int) 1000.0f / UPDATE_RATE, update, v);
    //1.11 fehler da ungenauigkeit besteht wenn
    //1000/60, also 16,666... um fehler zu
    //vermeiden könnte man eine andere Werte
    //wählen,zb 50 oder anderen datentyp, da
    //float nicht sehr genau ist
}
*/

// Handler for window resize and creation event
void MyGLWidget::resizeGL(GLsizei width, GLsizei height)
{
   // Compute aspect ratio
   height = (height == 0) ? 1 : height;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set viewport to cover the whole window
   glViewport(0, 0, width, height);

   // Set projection matrix to a perspective projection
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   //gluPerspective(45.0f, aspect, 0.1, 100.0);

   //1.10 Othogonale Pespektiv und Ortogonal
  //glOrtho(-3,3,-3,3,0.1,100);
   glFrustum(-0.05, 0.05, -0.05, 0.05, 0.1, 100.0);
}


// Handler for window draw event
void MyGLWidget::paintGL()
{
    // Clear buffer to set color and alpha
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Apply model view transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glTranslatef(0.0f, 0.0f, -7.0f);
    glTranslatef(xachse,yachse,zoom);
    // Set color for drawing
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    //1.5 Rotation
    //glRotatef(45.0,0.0,0.0,1.0);
     glRotatef(slide,1.0f,1.0f,1.0f);
    //1.6 Oberfläche
    glRotatef(180.0,0.0,1.0,0.0);
    //1.7 Drehung in y-Richtung
    counter= counter +1;
    glRotatef(counter,0.0,1.0,0.0);
    // Draw shape
   /* glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex3f( 1.0f, -1.0f,  0.0f); //ul
        glColor3f(0,0,1);//b
        glVertex3f( 1.0f,  1.0f,  0.0f); //or
        glColor3f(0,1,0);//c
        glVertex3f(-1.0f,  1.0f,  0.0f); //ol
        glColor3f(1,0,0);
        glVertex3f(1,-1,0); //ul
        glColor3f(0,1,0);
        glVertex3f(-1,1,0); //ol
        glColor3f(1,1,0);//d
        glVertex3f(-1.0f,-1.0f,0.0f); //ul
    glEnd();
    */

    glBegin(GL_QUADS);
        //TOP_counterclockwise
        glColor3f(1.0f, 1.0f, 0.0f);//yellow
        glVertex3f( -1.0f, 1.0f,  -1.0f);//D
        glColor3f(0.737255f, 0.560784f, 0.560784f);//pink
        glVertex3f( -1.0f, 1.0f,  1.0f);//H
        glColor3f(1.0f, 0.5f, 0.0f);//orange
        glVertex3f( 1.0f, 1.0f,  1.0f);//G
        glColor3f(0.0f, 1.0f, 0.0f);//green
        glVertex3f( 1.0f, 1.0f,  -1.0f);//C

        //Back_clockwise
        glColor3f(1.0f, 0.0f, 0.0f);//red
        glVertex3f( -1.0f, -1.0f,  -1.0f);//A
        glColor3f(1.0f, 1.0f, 0.0f);//yellow
        glVertex3f( -1.0f, 1.0f,  -1.0f);//D
        glColor3f(0.0f, 1.0f, 0.0f);//green
        glVertex3f( 1.0f, 1.0f,  -1.0f);//C
        glColor3f(0.0f, 0.0f, 1.0f);//blue
        glVertex3f( 1.0f, -1.0f,  -1.0f);//B

        //RIGHT_counterclockwise
        glColor3f(0.0f, 1.0f, 0.0f);//green
        glVertex3f( 1.0f, 1.0f,  -1.0f);//C
        glColor3f(1.0f, 0.5f, 0.0f);//orange
        glVertex3f( 1.0f, 1.0f,  1.0f);//G
        glColor3f(1.0f, 0.0f, 1.0f);//magenta
        glVertex3f( 1.0f, -1.0f,  1.0f);//F
        glColor3f(0.0f, 0.0f, 1.0f);//blue
        glVertex3f( 1.0f, -1.0f,  -1.0f);//B

        //LEFT_clockwise
        glColor3f(1.0f, 0.0f, 0.0f);//red
        glVertex3f( -1.0f, -1.0f,  -1.0f);//A
        glColor3f(0.0f, 1.0f, 1.0f);//cyan
        glVertex3f( -1.0f, -1.0f,  1.0f);//E
        glColor3f(0.737255f, 0.560784f, 0.560784f);//pink
        glVertex3f( -1.0f, 1.0f,  1.0f);//H
        glColor3f(1.0f, 1.0f, 0.0f);//yellow
        glVertex3f( -1.0f, 1.0f,  -1.0f);//D

        //Front_counterclockwise
        glColor3f(1.0f, 0.5f, 0.0f);//orange
        glVertex3f( 1.0f, 1.0f,  1.0f);//G
        glColor3f(0.737255f, 0.560784f, 0.560784f);//pink
        glVertex3f( -1.0f, 1.0f,  1.0f);//H
        glColor3f(0.0f, 1.0f, 1.0f);//cyan
        glVertex3f( -1.0f, -1.0f,  1.0f);//E
        glColor3f(1.0f, 0.0f, 1.0f);//magenta
        glVertex3f( 1.0f, -1.0f,  1.0f);//F

        //BOTTOM_clockwise
        glColor3f(1.0f, 0.0f, 0.0f);//red
        glVertex3f( -1.0f, -1.0f,  -1.0f);//A
        glColor3f(0.0f, 0.0f, 1.0f);//blue
        glVertex3f( 1.0f, -1.0f,  -1.0f);//B
        glColor3f(1.0f, 0.0f, 1.0f);//magenta
        glVertex3f( 1.0f, -1.0f,  1.0f);//F
        glColor3f(0.0f, 1.0f, 1.0f);//cyan
        glVertex3f( -1.0f, -1.0f,  1.0f);//E
    glEnd();

    // Execute all issued GL commands
   // glFlush(); // replace with glutSwapBuffers() for double buffered mode
     QOpenGLWidget::update();

    // Increment counter
   // counter++;
}

void MyGLWidget::receiveRotationZ(int wert){

    slide = wert;

}

void MyGLWidget::keyPressEvent(QKeyEvent *event)
{
    switch ( event->key())
      {  case Qt::Key_Up:
           yachse+=0.1f;
         break;

         case  Qt::Key_Down:
           yachse-=0.1f;
         break;

         case  Qt::Key_Left:
            xachse-=0.1f;
         break;

         case Qt::Key_Right:
            xachse+=0.1f;
         break;

         case Qt::Key_W:
            yachse+=0.1f;
         break;

         case  Qt::Key_S:
            yachse-=0.1f;
         break;

         case  Qt::Key_A:
            xachse-=0.1f;
         break;

         case Qt::Key_D:
            xachse+=0.1f;
         break;
      }
    /*
    else {
    QOpenGLWidget::keyPressEvent(event);
    }
    */
}

void MyGLWidget::wheelEvent(QWheelEvent* event)
{
    int numDegrees = event->delta() / 120;
       int numSteps = numDegrees / 1;

       if (event->orientation() == Qt::Horizontal) {
           zoom+=numSteps;
           emit valueChanged(zoom);
       } else {
           zoom-=numSteps;
           emit valueChanged(zoom);
       }
       //emit zoom
       event->accept();
}
