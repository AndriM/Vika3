#include "removeconfirm.h"
#include "ui_removeconfirm.h"

RemoveConfirm::RemoveConfirm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveConfirm)
{
    ui->setupUi(this);
}

RemoveConfirm::~RemoveConfirm()
{
    delete ui;
}

void RemoveConfirm::on_yes_button_clicked()
{
    button = true;
    close();
}

void RemoveConfirm::on_no_button_clicked()
{
    button = false;
    close();
}
