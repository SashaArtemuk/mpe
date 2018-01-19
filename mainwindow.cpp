#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <list>
#include "variablesdialog.h"
#include <QDebug>
#include <QMenu>
#include "savedialog.h"
#include <fstream>
#include <grafik.h>
#include <funcs/CustomFunc.h>
#include <funcs/AbstractF.h>
#include <QDirIterator>
#include <QValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    collection = new Collection;
    std::ifstream f1(("funcs.txt"));
    if(f1.good())
        collection->load(("funcs.txt"));
    visualise();
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget,SIGNAL(customContextMenuRequested(QPoint)),
            this,SLOT(variablesTableWidgetCustomContextMenuRequested(QPoint)));
    connect(ui->tableView,SIGNAL(customContextMenuRequested(QPoint)),
            this,SLOT(funcsTableWidgetCustomContextMenuRequested(QPoint)));
    ui->lineEdit->setValidator( new QRegExpValidator( QRegExp( "\\S+" ) ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::visualise()
{
        int size=collection->flist.size();
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *item;
        ui->tableView->setModel(model);
        QStringList horizontalHeader;
        horizontalHeader.append("Назва");
        horizontalHeader.append("Тип");
        horizontalHeader.append("Пріоритет");
        horizontalHeader.append("К-сть аргументів");
      //  horizontalHeader.append("Фукнція");

        QStringList verticalHeader;
        QString str;
        for(int i=0;i<size;i++){
            str=QString::fromStdString(collection->flist[i]->getName());
            item = new QStandardItem(str);
            model->setItem(i, 0, item);
            int t=collection->flist[i]->getType();
            if(t==AbstractF::consta)
                str="Константа";
            if(t==AbstractF::func)
                str="Функція";
            if(t==AbstractF::operatr)
                str="Оператор";
            item = new QStandardItem(str);
            model->setItem(i, 1, item);
            str=QString::number(collection->flist[i]->getPriority());
            item = new QStandardItem(str);
            model->setItem(i, 2, item);
            str=QString::number(collection->flist[i]->getCount());
            item = new QStandardItem(str);
            model->setItem(i, 3, item);
            str="";
          /*  for(int j=0;i<collection->flist[i]->getVelement().size();j++){
            if(collection->flist[i]->getVelement[j].type==Celement::var)
                str=QString::fromStdString(collection->flist[i]->getVelement[j].name);
            if(collection->flist[i]->getVelement[j].type==Celement::consta)
                str=QString::number(collection->flist[i]->getVelement[j].value);
            if(collection->flist[i]->getVelement[j].type==Celement::func)
                str=QString::fromStdString(collection->flist[i]->getVelement[j].f->getName());
           } */
           // item = new QStandardItem(str);
           // model->setItem(i, 1, item);
        }

        model->setVerticalHeaderLabels(verticalHeader);
        model->setHorizontalHeaderLabels(horizontalHeader);
        ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
      //  ui->tableView->horizontalHeader()->resizeSection(1, 155);
      //  ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}



void MainWindow::on_pushButton_clicked()
{
    Melements *elems;
    Parser *parser;
    Compilator *compiler;
    Calculator *calc;
    elems = new Melements;
    parser=new Parser(collection,elems);
    compiler=new Compilator;
    calc=new Calculator;
    parser->setLengs();
    compiler->collection=collection;
    try{
        parser->parse((ui->lineEdit->text()).toStdString());
    }
    catch (std::exception &e){
        QMessageBox::critical(this,"Error",e.what());
        return;
     }
    try{
    compiler->compile(elems);
    }
    catch (std::exception &e){
       QMessageBox::critical(this,"Error",e.what());
       return;
    }
    Velement v=compiler->v;
    calc->setVelement(v);
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        calc->setVariable(ui->tableWidget->item(i,0)->text().toStdString(),ui->tableWidget->item(i,1)->text().toDouble());
    }
    std::vector<std::string> variables=calc->getUnknownVariables();
   for(int i=0;i<variables.size();i++){
       VariablesDialog dialog;
       dialog.setEnabled(false);
       dialog.setName(QString::fromStdString(variables[i]));
       if(dialog.exec()==QDialog::Accepted){
           ui->tableWidget->blockSignals(true);
           ui->tableWidget->insertRow(0);
           ui->tableWidget->setItem(0,0,new QTableWidgetItem(dialog.getName()));
           ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(dialog.getVal())));
           calc->setVariable(variables[i],dialog.getVal());
           ui->tableWidget->blockSignals(false);
        }else return;
    }
    try{
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
       ui->lineEdit_3->setText(ss);
            ui->lineEdit_2->setText(QString::number(calc->calc()));
        }
    catch (std::exception &e){
       QMessageBox::critical(this,"Error",e.what());
       return;
    }
}

void MainWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{

}

void MainWindow::on_pushButton_3_clicked()
{
      VariablesDialog dialog;
      dialog.setEnabled(true);
      if(dialog.exec()==QDialog::Accepted){
      ui->tableWidget->blockSignals(true);
      for(int i=0;i<ui->tableWidget->rowCount();i++){
         if(ui->tableWidget->item(i,0)->text()==dialog.getName()){
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(dialog.getVal())));
            ui->tableWidget->blockSignals(false);
            return;
         }
      }
      ui->tableWidget->insertRow(0);
      ui->tableWidget->setItem(0,0,new QTableWidgetItem(dialog.getName()));
      ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(dialog.getVal())));
      ui->tableWidget->blockSignals(false);
      }
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if (item->column()==0){
        ui->lineEdit_2->clear();
        return;
    }
    on_pushButton_clicked();
}

void MainWindow::variablesTableWidgetCustomContextMenuRequested(QPoint p)
{
    QPoint globalPos=ui->tableWidget->mapToGlobal(p);
    QMenu menu;
    menu.addAction("Remove",this,SLOT(removeVar()));
    menu.addAction("Add",this,SLOT(on_pushButton_3_clicked()));
    menu.exec(globalPos);

}

void MainWindow::funcsTableWidgetCustomContextMenuRequested(QPoint p){
    QPoint globalPos=ui->tableView->mapToGlobal(p);
    QMenu menu;
    menu.addAction("Remove",this,SLOT(removeF()));
    menu.exec(globalPos);
}

void MainWindow::removeVar()
{
    if(ui->tableWidget->selectedItems().isEmpty())
        return;
    ui->tableWidget->removeRow(ui->tableWidget->selectedItems().at(0)->row());
    ui->lineEdit_2->clear();
}

void MainWindow::removeF(){
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    int ind=index.row();
    AbstractF* item=collection->flist[ind];
    if(selection.isEmpty() || !(dynamic_cast<CustomFunc*>(item)))
        return;
    ui->lineEdit_2->clear();
    collection->flist.erase(collection->flist.begin()+ind);
    visualise();
    collection->save(("funcs.txt"));
}

void MainWindow::on_pushButton_2_clicked()
{

    Melements *elems;
    Parser *parser;
    Compilator *compiler;
    Calculator *calc;
    elems = new Melements;
    parser=new Parser(collection,elems);
    compiler=new Compilator;
    calc=new Calculator;
    parser->setLengs();
    compiler->collection=collection;
    parser->parse((ui->lineEdit->text()).toStdString());
    compiler->compile(elems);
    Velement v=compiler->v;
    SaveDialog dia;
    dia.v=v;
    dia.setAll();
    dia.collection=collection;
    if(dia.exec()==QDialog::Accepted){
        visualise();
        collection->save((QDir::currentPath()+"/funcs.txt").toStdString());
    }
}

void MainWindow::on_tableView_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_pushButton_4_clicked()
{
    Grafik gr;
    Melements *elems;
    Parser *parser;
    Compilator *compiler;
    Calculator *calc;
    elems = new Melements;
    parser=new Parser(collection,elems);
    compiler=new Compilator;
    calc=new Calculator;
    parser->setLengs();
    compiler->collection=collection;
    parser->parse((ui->lineEdit->text()).toStdString());
    compiler->compile(elems);
    Velement v=compiler->v;
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        gr.addVar(ui->tableWidget->item(i,0),ui->tableWidget->item(i,1));
    }
    gr.setLabel(ui->lineEdit->text());
    gr.v=v;
    gr.velement();
    gr.exec();
}
