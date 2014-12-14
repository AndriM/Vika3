#ifndef COMPUTERADD_H
#define COMPUTERADD_H

#include "computer.h"
#include <QWidget>

namespace Ui {
class ComputerAdd;
}

class ComputerAdd : public QWidget
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

private:
    Ui::ComputerAdd *ui;
    Computer newComputer;
};

#endif // COMPUTERADD_H
