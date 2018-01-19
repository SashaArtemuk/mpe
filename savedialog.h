#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H
#include "elems/Velement.h"
#include "collection.h"
#include <QDialog>

namespace Ui {
class SaveDialog;
}

class SaveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveDialog(QWidget *parent = 0);
    ~SaveDialog();
    Velement v;
    void setAll();
    Collection *collection;
    AbstractF::Type type;
    struct Var{
        std::string name;
        std::string arg;
    };

    std::vector<Var> vars;
    bool wasVar(Var a);
    int findVar(Var a);


private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::SaveDialog *ui;
};

#endif // SAVEDIALOG_H
