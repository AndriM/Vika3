#include "computeradd.h"
#include "ui_computeradd.h"

ComputerAdd::ComputerAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerAdd)
{
    ui->setupUi(this);
}

Computer ComputerAdd::getComputer()
{
    return newComputer;
}

ComputerAdd::~ComputerAdd()
{
    delete ui;
}
void ComputerAdd::on_compname_textChanged(const QString &arg1)
{
    newComputer.name = ui->compname->text().toStdString();
}

void ComputerAdd::on_comptype_textChanged(const QString &arg1)
{
    newComputer.type = ui->comptype->text().toStdString();
}

void ComputerAdd::on_builtyes_toggled(bool checked)
{
    if(checked)
    {
        ui->yearLine->setEnabled(true);
    }
    else
    {
        ui->yearLine->setEnabled(false);
    }
}

void ComputerAdd::on_yearLine_textChanged(const QString &arg1)
{
    newComputer.yearBuilt = ui->yearLine->text().toStdString();
}

void ComputerAdd::on_add_clicked()
{
    Computer newComputer = getComputer();
    scienceService.addComputer(newComputer);
    close();
}
