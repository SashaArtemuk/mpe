#include "grafik.h"
#include "ui_grafik.h"
#include "Calculator.h"
#include <vector>
#include "coord.h"
#include "variablesdialog.h"
#include <QMessageBox>

Grafik::Grafik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grafik)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = windowFlags();

    flags &= ~Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowMaximizeButtonHint;
    setWindowFlags(flags);

    ui->ogl->blockSignals(true);
    connect(ui->ogl, SIGNAL(dotXChanged(double)), this, SLOT(dotXChanged(double)));
}

Grafik::~Grafik()
{
    delete ui;
}

void Grafik::addVar(QTableWidgetItem* i1, QTableWidgetItem* i2)
{
        ui->tableWidget->blockSignals(true);
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(i1->text()));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(i2->text()));
        ui->tableWidget->blockSignals(false);
}

void Grafik::setLabel(QString s)
{
    ui->label->setText(s);
}

void Grafik::velement()
{
    for(int i=0;i<v.vec.size();i++){
        if(v.vec[i].t==Celement::var)
            ui->comboBox->addItem(QString::fromStdString(v.vec[i].name));
    }
}

void Grafik::dotXChanged(double x)
{
    Calculator calc;
    calc.setVelement(v);
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        if(ui->tableWidget->item(i,0)->text()!=ui->comboBox->itemText(ui->comboBox->currentIndex()))
            calc.setVariable(ui->tableWidget->item(i,0)->text().toStdString(),(ui->tableWidget->item(i,1)->text()).toDouble());
    }
    calc.setVariable(ui->comboBox->currentText().toStdString(), x);

    try {
        double y = calc.calc();
        setWindowTitle(QString("PME - Plot: x=%1; y=%2").arg(x).arg(y));
    }
    catch (...)
    {
        setWindowTitle(QString("PME - Plot: - "));
    }

}


void Grafik::on_pushButton_clicked()
{
    ui->ogl->blockSignals(false);
    if(ui->spinBox_2->value()<=ui->spinBox->value())
        return;
    double t=ui->spinBox_2->value()-ui->spinBox->value();
    double t2=ui->spinBox_3->value();
    double krok=t/t2;
    Calculator calc;
    calc.setVelement(v);
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        if(ui->tableWidget->item(i,0)->text()!=ui->comboBox->itemText(ui->comboBox->currentIndex()))
            calc.setVariable(ui->tableWidget->item(i,0)->text().toStdString(),(ui->tableWidget->item(i,1)->text()).toDouble());
    }
    std::vector<std::string> variables=calc.getUnknownVariables();
    for(int i=0;i<variables.size();i++){
       if(variables[i]==ui->comboBox->itemText(ui->comboBox->currentIndex()).toStdString())
           continue;
       VariablesDialog dialog;
       dialog.setEnabled(false);
       dialog.setName(QString::fromStdString(variables[i]));
       if(dialog.exec()==QDialog::Accepted){
           ui->tableWidget->blockSignals(true);
           ui->tableWidget->insertRow(0);
           ui->tableWidget->setItem(0,0,new QTableWidgetItem(dialog.getName()));
           ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(dialog.getVal())));
           calc.setVariable(variables[i],dialog.getVal());
           ui->tableWidget->blockSignals(false);
        }else return;
    }

    std::vector<Coord> dots;
    for(double i=ui->spinBox->value();i<ui->spinBox_2->value();i+=krok){
        Coord t;
        t.x=i;
        calc.setVariable(ui->comboBox->itemText(ui->comboBox->currentIndex()).toStdString(),i);
        try{
            t.y=calc.calc();
        }catch (std::exception &e){
            continue;
        }
        dots.push_back(t);
    }
    ui->ogl->setPos(t,(ui->spinBox->value()+ui->spinBox_2->value())/2);
    ui->ogl->setDots(dots);
    ui->ogl->update();
}

