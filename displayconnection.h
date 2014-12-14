#ifndef DISPLAYCONNECTION_H
#define DISPLAYCONNECTION_H

#include <QDialog>

namespace Ui {
class displayConnection;
}

class displayConnection : public QWidget
{
    Q_OBJECT

public:
    explicit displayConnection(QWidget *parent = 0);
    ~displayConnection();

private:
    Ui::displayConnection *ui;
};

#endif // DISPLAYCONNECTION_H
