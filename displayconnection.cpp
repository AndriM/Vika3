#include "displayconnection.h"
#include "ui_displayconnection.h"

displayConnection::displayConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayConnection)
{
    ui->setupUi(this);
}

displayConnection::~displayConnection()
{
    delete ui;
}