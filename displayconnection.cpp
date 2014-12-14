#include "displayconnection.h"
#include "ui_displayconnection.h"

displayConnection::displayConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayConnection)
{
    ui->setupUi(this);
}

displayConnection::~displayConnection()
{
    delete ui;
}
