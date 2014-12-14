#include "scientistbase.h"
#include "ui_scientistbase.h"

Scientistbase::Scientistbase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scientistbase)
{
    ui->setupUi(this);
}

Scientistbase::~Scientistbase()
{
    delete ui;
}

void Scientistbase::on_searchBar_textEdited(const QString &arg1)
{

}

void Scientistbase::on_addButton_clicked()
{
    scientistadd sciAdd;
    sciAdd.exec();
}

void Scientistbase::on_button_connect_clicked()
{
    connection connect;
    connect.exec();
}

void Scientistbase::on_button_disp_conn_clicked()
{
    displayConnection disConn;
    disConn.exec();
}

void Scientistbase::on_backButton_clicked()
{
    close();
}
