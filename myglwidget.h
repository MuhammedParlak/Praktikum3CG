#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QObject>
#include <QKeyEvent>
#include <QWheelEvent>

class MyGLWidget : public QOpenGLWidget
{
    //Für die Singals und Slots,sonst wird dies nicht registriert

    Q_OBJECT
private:
    unsigned int counter = 0;
    unsigned int slide = 0;
    float xachse=0;
    float yachse = 0;
    float zoom = -7;
public:
    MyGLWidget();
    MyGLWidget(QWidget *parent) : QOpenGLWidget(parent) {
          setFocusPolicy(Qt::StrongFocus);
    }
   // void init();
   // void reshape(GLsizei width, GLsizei height );
   // void draw();
    void initializeGL();
    void resizeGL(GLsizei width, GLsizei height);
    void paintGL();
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

public slots:
    void receiveRotationZ(int wert);

signals:
    void valueChanged(int Wert);
};

#endif // MYGLWIDGET_H
