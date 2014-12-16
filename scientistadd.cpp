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
    if(nameLineValid())
    {
        newScientist.name = ui->nameLine->text().toStdString();
    }
}

void scientistadd::on_byLine_textChanged(const QString &arg1)
{
    if(yearOfBirthValid())
    {
        newScientist.dateOfBirth = ui->byLine->text().toStdString();
    }
}

void scientistadd::on_dyLine_textChanged(const QString &arg1)
{
    if(deathYearValid())
    {
        newScientist.dateOfDeath = ui->dyLine->text().toStdString();
    }
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
    if(nameLineValid() && yearOfBirthValid() && deathYearValid())
    {
    Scientist newScientist = getScientist();
    scienceService.addScientist(newScientist);
    close();
    }
}

void scientistadd::on_backButton_clicked()
{
    close();
}
void scientistadd::on_photoButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                        "Browse for image...",
                        "",
                        "Image files (*.png *.jpg *.jpeg *.bmp)"
                        );

    ui->imageLine->setText(filename);

    newScientist.imagePath = ui->imageLine->text().toStdString();

}
bool scientistadd::nameLineValid()
{
    
    if(ui->nameLine->text().isEmpty())
    {
        QMessageBox::warning(this,"Error input.", " Name line is empty!");
        return false;
    }
   /* if(ui->nameLine->text().isDigit())
    {
        QMessageBox::warning(this,"Error input.", " Name line cannot contain a digit");
        return false;
    }*/
    
    return true;
}
bool scientistadd::yearOfBirthValid()
{
    
    if(ui->byLine->text().isEmpty())
    {
        QMessageBox::warning(this,"Error input.", " Birth year is empty!");
        return false;
    }
    /*if(ui->byLine->text().isAlpha())
    {
        QMessageBox::warning(this,"Error input.", " Birth year cannot contain a alpha");
        return false;
    }*/
    
    return true;
    
}
bool scientistadd::deathYearValid()
{
    
    if(ui->dyLine->text().isEmpty())
    {
        QMessageBox::warning(this,"Error input.", " Death year is empty!");
        return false;
    }
    /*if(ui->dyLine->text().isAlpha())
    {
        QMessageBox::warning(this,"Error input.", " Death year cannot contain a alpha");
        return false;
    }*/
    
    return true;
}
/*bool genderValid()
{
    
}*/
