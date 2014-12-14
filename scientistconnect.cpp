#include "scientistconnect.h"
#include "ui_scientistconnect.h"

scientistConnect::scientistConnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistConnect)
{
    ui->setupUi(this);
}

scientistConnect::~scientistConnect()
{
    delete ui;
}
