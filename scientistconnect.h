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
private slots:
    void on_backButton_clicked();
    void on_connectButton_clicked();
private:
    Ui::scientistConnect *ui;
};

#endif // SCIENTISTCONNECT_H
