#include "computeradd.h"
#include "ui_computeradd.h"
#include <QDebug>

ComputerAdd::ComputerAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComputerAdd)
{
    ui->setupUi(this);
}

ComputerAdd::~ComputerAdd()
{
    delete ui;
}


