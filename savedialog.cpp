#include "savedialog.h"
#include "setargs.h"
#include "ui_savedialog.h"
#include "funcs/CustomFunc.h"
#include "funcs/AbstractF.h"
#include <vector>

SaveDialog::SaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveDialog)
{
    ui->setupUi(this);
}

SaveDialog::~SaveDialog()
{
    delete ui;
}

bool SaveDialog::wasVar(Var a){
    for(int j=0;j<vars.size();j++)
        if(a.name == vars[j].name)
            return true;
}

int SaveDialog::findVar(Var a){
    for(int j=0;j<vars.size();j++)
        if(a.name == vars[j].name)
            return j;
}

void SaveDialog::setAll()
{
    int t=0;
      int count=0;
      QString s;

      for(int i=0;i<v.vec.size();i++){
          if(v.vec[i].t==Celement::var){
              Var tt;
              tt.name=v.vec[i].name;
              tt.arg=("arg"+QString::number(count)).toStdString();
              if(!wasVar(tt)){
                  t++;
                  vars.push_back(tt);
                  s="arg"+QString::number(count);
                  v.vec[i]=Celement::fromVar(s.toStdString());
                  count++;
              }else{
                  s="arg"+QString::number(findVar(tt));
                  v.vec[i]=Celement::fromVar(s.toStdString());
              }

              }
          }
      count=0;
    if(!t){
        ui->comboBox->addItem("Константа");
        type=AbstractF::consta;
        ui->spinBox->setEnabled(false);
        ui->spinBox->setValue(0);
        ui->spinBox_2->setEnabled(false);
    }
    if(t>=1){
        ui->comboBox->addItem("Функція");
        type=AbstractF::func;
        ui->spinBox->setEnabled(false);
        ui->spinBox->setValue(t);
        ui->spinBox_2->setEnabled(true);
    }
    if(t==2){
        ui->comboBox->addItem("Оператор");
        type=AbstractF::operatr;
        ui->spinBox->setEnabled(false);
        ui->spinBox_2->setEnabled(true);
    }
    ui->spinBox->setValue(t);
    QString ss;
    for(int i=0;i<v.vec.size();i++){
        if(v.vec[i].t==Celement::consta){
            ss+=QString::number(v.vec[i].value)+" ";
        }
        if(v.vec[i].t==Celement::func){
            ss+=QString::fromStdString(v.vec[i].f->getName())+" ";
        }
        if(v.vec[i].t==Celement::var){
            ss+=QString::fromStdString(v.vec[i].name)+" ";
        }
    }
    ui->label_5->setText(ss);
}

void SaveDialog::on_comboBox_currentIndexChanged(int index)
{

}

void SaveDialog::on_pushButton_3_clicked()
{

}

void SaveDialog::on_pushButton_clicked()
{
    AbstractF *f=new CustomFunc(ui->lineEdit->text().toStdString(),ui->spinBox_2->value(),collection,v,type,ui->spinBox->value()) ;
    collection->flist.push_back((f));
}

void SaveDialog::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1=="Функція"){
        ui->spinBox->setEnabled(true);
        ui->spinBox_2->setEnabled(true);
        type=AbstractF::func;
    }
    else if(arg1=="Оператор"){
        ui->spinBox->setEnabled(false);
        ui->spinBox_2->setEnabled(true);
        type=AbstractF::operatr;
        }
    else if(arg1=="Константа"){
        ui->spinBox->setEnabled(false);
        ui->spinBox->setValue(0);
        ui->spinBox_2->setEnabled(false);
        type=AbstractF::consta;
        }
}
