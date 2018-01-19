#include "variablesdialog.h"
#include "ui_variablesdialog.h"

VariablesDialog::VariablesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VariablesDialog)
{
    ui->setupUi(this);
}



VariablesDialog::~VariablesDialog()
{
    delete ui;
}

void VariablesDialog::setName(QString name)
{
    ui->lineEdit->setText(name);
}

void VariablesDialog::setEnabled(bool t)
{
    ui->lineEdit->setEnabled(t);
}

double VariablesDialog::getVal()
{
    return ui->doubleSpinBox->value();
}

QString VariablesDialog::getName()
{
    return ui->lineEdit->text();
}

void VariablesDialog::on_lineEdit_textChanged(const QString &arg1)
{
    ui->pushButton_2->setEnabled((ui->lineEdit->text().length()));
}
