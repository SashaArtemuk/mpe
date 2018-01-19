#include "ogl.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include <QDebug>
#include <QMouseEvent>

Ogl::Ogl(QWidget *parent) : QOpenGLWidget(parent)
{
    canDrawGrid = true;
    gridLinesCount = 20;
    y=2.5;
    x=0;
    z=0;
    setMouseTracking(true);
    isMousePressed = false;
}

void Ogl::setDots(std::vector<Coord> dots1)
{
    dots=dots1;
    minX = 0;
    maxX = 0;
    minY = 0;
    maxY = 0;

    if (dots.size() == 0)
        return;

    minX = dots.front().x;
    maxX = dots.back().x;
    minY;
    maxY;
}


void Ogl::setPos(double t,double t1){
    y=t;
    x=t1;
}

void Ogl::moveX(double t)
{
    x=t;
}

void Ogl::moveY(double t)
{
    z=t;
}

void Ogl::moveZ(double t){
    y=t;
}

void Ogl::initializeGL()
{
      glClearColor(0,0,0,1);
      glEnable(GL_DEPTH_TEST);
      glEnable(GL_LIGHT0);
      glEnable(GL_LIGHTING);
      glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
      glEnable(GL_COLOR_MATERIAL);
}

void Ogl::resizeGL(int w, int h)
{
      glViewport(0,0,w,h);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(45, (float)w/h, 0.01, 1000000.0);
}

void Ogl::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x,z,y,x,z,0,0,1,0);

    drawGrid();
    drawMainLines();
    drawPlot();

    if (!isMousePressed)
    {
        double px = translatePointXToPlotX(lastPos.x());
        glColor3f(0.827, 0.827, 0.827);
        glBegin(GL_LINES);
        glVertex3f(px, -10000, 0);
        glVertex3f(px, 10000, 0);
        glEnd();

        emit dotXChanged(px);
    }
}

void Ogl::mousePressEvent(QMouseEvent *event)
{
    isMousePressed = true;
    lastPos = event->pos();
}

void Ogl::mouseReleaseEvent(QMouseEvent *event)
{
    isMousePressed = false;
}

void Ogl::mouseMoveEvent(QMouseEvent *event)
{
    if (isMousePressed)
    {
        double dx = event->x() - lastPos.x();
        double dy = event->y() - lastPos.y();

        x -= dx * y / 250.0;
        z += dy * y / 250.0;
    }

    lastPos = event->pos();

    update();
}

void Ogl::wheelEvent(QWheelEvent *event)
{
    double p = event->angleDelta().y();

    if (p < 0)
        y += 1;
    else
        y -= 1;

    if (y < 0)
        y = 0.1;


    event->accept();
    update();
}

void Ogl::drawPlot()
{
    glColor3f(1, 0, 0.0);
    glBegin(GL_POINTS);
        for(int i=0;i<dots.size();i++){
            glVertex3f(dots[i].x,dots[i].y, 0);
        }
    glEnd();
}

void Ogl::drawGrid()
{
    return;
    double stepX = (maxX-minX)/gridLinesCount;
    if (stepX == 0)
        return;
    glColor3f(0.827, 0.827, 0.827);
    glPushAttrib(GL_ENABLE_BIT);

    glLineStipple(1, 0x00FF);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    for (double x=minX; x<=maxX; x+=stepX)
    {
        glVertex3f(x, -10000, 0);
        glVertex3f(x, 10000, 0);
    }
    glEnd();

    glPopAttrib();
}

void Ogl::drawMainLines()
{
    glColor3f(0, 1, 0.0);
    glBegin(GL_LINE_STRIP);
        glVertex3f(-10000, 0, 0);
        glVertex3f(10000, 0, 0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f(0, 10000, 0);
        glVertex3f(0, -10000, 0);
        glEnd();
}

double Ogl::translatePointXToPlotX(int px)
{
    double s = (double)width() / height();
    double a = s * y * 0.414;

    return 2.0 * a * px / width() - a + x;
}
