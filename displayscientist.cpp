#include "displayscientist.h"
#include "ui_displayscientist.h"
#include <iostream>
displayScientist::displayScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayScientist)
{
    ui->setupUi(this);
}

displayScientist::~displayScientist()
{
    delete ui;
}

void displayScientist::displayPhoto(Scientist scientist)
{
    ui->label_title->setText(QString("<h2>%1</h2>").arg(QString::fromStdString(scientist.getName())));
    ui->byLabel->setText(QString("<h2>%1</h2>").arg(QString::fromStdString(scientist.getDateOfBirth())));
    ui->genderLabel->setText(QString("<h2>%1</h2>").arg(QString::fromStdString(scientist.getGender())));

    if(scientist.getDateOfDeath() == "")
    {
        ui->dyLabel->setText(QString("<h2>%1</h2>").arg(QString::fromStdString("Still Alive")));
    }
    else
    {
        ui->dyLabel->setText(QString("<h2>%1</h2>").arg(QString::fromStdString(scientist.getDateOfDeath())));
    }
    ui->ybLabel->setText(QString("<h3>%1</h3>").arg(QString::fromStdString("Year of birth:")));
    ui->ydLabel->setText(QString("<h3>%1</h3>").arg(QString::fromStdString("Year of death:")));

    QPixmap pixmap(QString::fromStdString(scientist.getImagepath()));

    int imageLabelWidth = ui->photoLabel->width();
    QPixmap scaledPixMap = pixmap.scaledToWidth(imageLabelWidth);

    ui->photoLabel->setPixmap(scaledPixMap);
}
