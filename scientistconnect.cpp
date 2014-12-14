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

void scientistConnect::on_backButton_clicked()
{
    close();
}

void scientistConnect::on_connectButton_clicked()
{
    //setja inn koda fyrir tengingu scientist-comp
    close();
}
