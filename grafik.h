#ifndef GRAFIK_H
#define GRAFIK_H
#include <ogl.h>
#include <QDialog>
#include <elems/Velement.h>
#include <QTableWidgetItem>
namespace Ui {
class Grafik;
}

class Grafik : public QDialog
{
    Q_OBJECT

public:
    explicit Grafik(QWidget *parent = 0);
    ~Grafik();
    Velement v;
    void addVar(QTableWidgetItem *i1, QTableWidgetItem *i2);
    void setLabel(QString s);
    void velement();


private slots:
    void dotXChanged(double x);

    void on_pushButton_clicked();

private:
    Ui::Grafik *ui;
};

#endif // GRAFIK_H
