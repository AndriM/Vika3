#include "computerbase.h"
#include "ui_computerbase.h"

Computerbase::Computerbase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Computerbase)
{
    ui->setupUi(this);
    ui->searchLine->setPlaceholderText("Search computers...");
}

Computerbase::~Computerbase()
{
    delete ui;
}

void Computerbase::on_addButton_clicked()
{
    ComputerAdd compAdd;
    compAdd.exec();
}

void Computerbase::on_button_disp_connected_clicked()
{
    displayConnection dispConn;
    dispConn.exec();
}

void Computerbase::on_button_connect_clicked()
{
    connection connect;
    connect.exec();
}

void Computerbase::on_backButton_clicked()
{
    close();
}
