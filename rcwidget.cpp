#include "rcwidget.h"

RCWidget::RCWidget(QWidget *parent):QGLWidget(parent)
{

}

void RCWidget::initializeGL()
{
    glClearColor(0.4,0.4,0.4,1.0);
    glEnable(GL_DEPTH_TEST);
}

void RCWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

}

void RCWidget::resizeGL(int w ,int h)
{

}
