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

Scientist scientistadd::getScientist()
{
    return newScientist;
}

void scientistadd::on_nameLine_textChanged(const QString &arg1)
{
    newScientist.name = ui->nameLine->text().toStdString();
}

void scientistadd::on_byLine_textChanged(const QString &arg1)
{
    newScientist.dateOfBirth = ui->byLine->text().toStdString();
}

void scientistadd::on_dyLine_textChanged(const QString &arg1)
{
    newScientist.dateOfDeath = ui->dyLine->text().toStdString();
}

void scientistadd::on_maleRadio_toggled(bool checked)
{
    if(checked)
    {
        newScientist.gender = "Male";
    }
}

void scientistadd::on_femaleRadio_toggled(bool checked)
{
    if(checked)
    {
        newScientist.gender = "Female";
    }
}

void scientistadd::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        ui->dyLine->setEnabled(false);
    }
    else
    {
        ui->dyLine->setEnabled(true);
    }
}

void scientistadd::on_addButton_clicked()
{
    Scientist newScientist = getScientist();
    scienceService.addScientist(newScientist);
    close();
}

void scientistadd::on_backButton_clicked()
{
    close();
}
