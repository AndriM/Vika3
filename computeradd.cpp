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
    if(nameLineValid())
    {
    newComputer.name = ui->compname->text().toStdString();
    }
}

void ComputerAdd::on_comptype_textChanged(const QString &arg1)
{
    if(typeValid())
    {
    newComputer.type = ui->comptype->text().toStdString();
    }
}

void ComputerAdd::on_yearLine_textChanged(const QString &arg1)
{
    newComputer.yearBuilt = ui->yearLine->text().toStdString();
}

void ComputerAdd::on_addButton_clicked()
{
    if(nameLineValid() && typeValid() && buildFieldValid())
    {
    Computer newComputer = getComputer();
    scienceService.addComputer(newComputer);
    close();
    }
}

void ComputerAdd::on_back_clicked()
{
    close();
}

void ComputerAdd::on_builtno_toggled(bool checked)
{
    no = true;
    yes = false;
    if(checked)
    {
        ui->yearLine->setEnabled(false);
    }
    else
    {
        ui->yearLine->setEnabled(true);
    }
    newComputer.wasBuilt = "No";
}

void ComputerAdd::on_builtyes_clicked()
{
    yes = true;
    no = false;
    newComputer.wasBuilt = "Yes";
}

bool ComputerAdd::nameLineValid()
{
    if(ui->compname->text().isEmpty())
    {
        QMessageBox::warning(this,"Error input.", " Computer name line is empty!");
        return false;
    }
    return true;
}

bool ComputerAdd::typeValid()
{
    if(ui->comptype->text().isEmpty())
    {
        QMessageBox::warning(this,"Error input.", " Type is empty!");
        return false;
    }
    return true;

}

bool ComputerAdd::buildFieldValid()
{
    if(yes == false && no == false)
    {
        QMessageBox::warning(this,"Error input.", " Build field is empty!");
        return false;
    }
    return true;
}
