#include "computerbase.h"
#include "ui_computerbase.h"

Computerbase::Computerbase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Computerbase)
{
    ui->setupUi(this);
}

Computerbase::~Computerbase()
{
    delete ui;
}
