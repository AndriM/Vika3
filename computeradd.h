#ifndef COMPUTERADD_H
#define COMPUTERADD_H

#include "computer.h"
#include <QDialog>

namespace Ui {
class ComputerAdd;
}

class ComputerAdd : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerAdd(QWidget *parent = 0);
    ~ComputerAdd();
    Computer getComputer();
private slots:

    void on_compname_textChanged(const QString &arg1);

    void on_comptype_textChanged(const QString &arg1);

    void on_builtyes_toggled(bool checked);

    void on_yearLine_textChanged(const QString &arg1);

    void on_add_clicked();

private:
    Ui::ComputerAdd *ui;
    Computer newComputer;
};

#endif // COMPUTERADD_H
