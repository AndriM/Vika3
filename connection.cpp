#include "connection.h"
#include "ui_connection.h"

connection::connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connection)
{
    ui->setupUi(this);
}

connection::~connection()
{
    delete ui;
}

void connection::on_backButton_clicked()
{
    close();
}

void connection::on_connectButton_clicked()
{
    //setja inn koda fyrir tengingu comp-scientist
    close();
}
