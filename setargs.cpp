#include "setargs.h"
#include "ui_setargs.h"

setArgs::setArgs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setArgs)
{
    ui->setupUi(this);
}

bool isPossible(QString t){
   if(t[0]=='a'&& t[1]=='r' && t[2]=='g')
       return false;
   else
       return true;
}

void setArgs::setAll(QString s,Velement v){
    ui->label->setText(s);
    name=s;
    this->v=v;
    for(int i=0;i<v.vec.size();i++){
        if(v.vec[i].t==Celement::var && isPossible(QString::fromStdString(v.vec[i].name)))
            ui->comboBox->addItem(QString::fromStdString(v.vec[i].name));
    }
    ind=ui->comboBox->itemText(0);
}

setArgs::~setArgs()
{
    delete ui;
}


void setArgs::on_comboBox_currentIndexChanged(int index)
{
    ind=ui->comboBox->itemText(index);
}

void setArgs::on_pushButton_clicked()
{

}
