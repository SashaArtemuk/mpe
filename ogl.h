#ifndef OGL_H
#define OGL_H
#include <QOpenGLWidget>
#include <vector>
#include "coord.h"

class Ogl : public QOpenGLWidget
{
    Q_OBJECT
signals:
    void dotXChanged(double x);

public:
    explicit Ogl(QWidget *parent = 0);
    std::vector<Coord> dots;
    void setDots(std::vector<Coord> dots1);
    void setPos(double t, double t1);
    void moveX(double t);
    void moveY(double t);
    void moveZ(double t);
    double y,x,z;

    bool canDrawGrid;
    int gridLinesCount;


protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent * event);

    void drawPlot();
    void drawGrid();
    void drawMainLines();

    double translatePointXToPlotX(int px);

    double minX;
    double maxX;
    double minY;
    double maxY;

    QPoint lastPos;
    QPoint hoverLastPos;

    bool isMousePressed;
};

#endif // OGL_H
