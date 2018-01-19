#ifndef VARIABLESDIALOG_H
#define VARIABLESDIALOG_H

#include <QDialog>

namespace Ui {
class VariablesDialog;
}

class VariablesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VariablesDialog(QWidget *parent = 0);
    ~VariablesDialog();
    void setName(QString name);
    void setEnabled(bool t);
    double getVal();
    QString getName();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::VariablesDialog *ui;
};

#endif // VARIABLESDIALOG_H
