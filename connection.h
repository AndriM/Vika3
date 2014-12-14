#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>

namespace Ui {
class connection;
}

class connection : public QDialog
{
    Q_OBJECT
public:
    explicit connection(QWidget *parent = 0);
    ~connection();
private slots:
    void on_backButton_clicked();
    void on_connectButton_clicked();
private:
    Ui::connection *ui;
};

#endif // CONNECTION_H
