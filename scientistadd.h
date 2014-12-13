#ifndef SCIENTISTADD_H
#define SCIENTISTADD_H

#include <QDialog>

namespace Ui {
class scientistadd;
}

class scientistadd : public QDialog
{
    Q_OBJECT

public:
    explicit scientistadd(QWidget *parent = 0);
    ~scientistadd();

private:
    Ui::scientistadd *ui;
};

#endif // SCIENTISTADD_H
