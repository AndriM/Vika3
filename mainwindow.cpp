#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonComputer_clicked()
{
    Computerbase computerbase;
    computerbase.exec();
}

void MainWindow::on_pushButtonScientist_clicked()
{
    Scientistbase scientistbase;
    scientistbase.exec();
}

void MainWindow::addComp()
{
    ComputerAdd compadd;
    compadd.exec();
    Computer newComputer = compadd.getComputer();
    scienceService.addComputer(newComputer);

}

void MainWindow::addScientist()
{
    scientistadd sciadd;
    sciadd.exec();
    Scientist newScientist = sciadd.getScientist();
    scienceService.addScientist(newScientist);
}
