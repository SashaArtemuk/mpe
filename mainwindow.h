#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "parser.h"
#include "collection.h"
#include "elems/melements.h"
#include "elems/Element.h"
#include "Calculator.h"
#include "Compilator.h"
#include <QTableWidgetItem>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Collection *collection;
    void visualise();



private slots:
    void on_pushButton_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void variablesTableWidgetCustomContextMenuRequested(QPoint p);

    void funcsTableWidgetCustomContextMenuRequested(QPoint p);

    void removeVar();

    void removeF();

    void on_pushButton_2_clicked();

    void on_tableView_customContextMenuRequested(const QPoint &pos);

    void on_tableWidget_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
