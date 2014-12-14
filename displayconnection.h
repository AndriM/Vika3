#ifndef DISPLAYCONNECTION_H
#define DISPLAYCONNECTION_H

#include <QDialog>

namespace Ui {
class displayConnection;
}

class displayConnection : public QDialog
{
    Q_OBJECT

public:
    explicit displayConnection(QWidget *parent = 0);
    ~displayConnection();

private slots:
    void on_backButton_clicked();

private:
    Ui::displayConnection *ui;
};

#endif // DISPLAYCONNECTION_H
