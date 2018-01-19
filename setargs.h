#ifndef SETARGS_H
#define SETARGS_H
#include <elems/Velement.h>
#include <QDialog>

namespace Ui {
class setArgs;
}

class setArgs : public QDialog
{
    Q_OBJECT

public:
    explicit setArgs(QWidget *parent = 0);
    void setAll(QString s, Velement v);
    Velement v;
    QString ind;
    QString name;
    ~setArgs();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::setArgs *ui;
};

#endif // SETARGS_H
