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
    ui->label_title->setText(QString("<h2>%1</h2>").arg(QString::fromStdString(scientist.toString())));

    QPixmap pixmap(QString::fromStdString(scientist.getImagepath()));

    int imageLabelWidth = ui->photoLabel->width();
    QPixmap scaledPixMap = pixmap.scaledToWidth(imageLabelWidth);

    ui->photoLabel->setPixmap(scaledPixMap);
}
