#ifndef COMPUTERADD_H
#define COMPUTERADD_H

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

private slots:

private:
    Ui::ComputerAdd *ui;
};

#endif // COMPUTERADD_H
