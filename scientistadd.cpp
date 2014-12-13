#include "scientistadd.h"
#include "ui_scientistadd.h"

scientistadd::scientistadd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistadd)
{
    ui->setupUi(this);
}

scientistadd::~scientistadd()
{
    delete ui;
}
