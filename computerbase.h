#ifndef COMPUTERBASE_H
#define COMPUTERBASE_H

#include <QDialog>

namespace Ui {
class Computerbase;
}

class Computerbase : public QDialog
{
    Q_OBJECT

public:
    explicit Computerbase(QWidget *parent = 0);
    ~Computerbase();

private:
    Ui::Computerbase *ui;
    //Computerbase computerbase;
};

#endif // COMPUTERBASE_H
