#ifndef SCIENTISTCONNECT_H
#define SCIENTISTCONNECT_H

#include <QDialog>

namespace Ui {
class scientistConnect;
}

class scientistConnect : public QDialog
{
    Q_OBJECT

public:
    explicit scientistConnect(QWidget *parent = 0);
    ~scientistConnect();

private:
    Ui::scientistConnect *ui;
};

#endif // SCIENTISTCONNECT_H
