#include "scientistconnect.h"
#include "ui_scientistconnect.h"

scientistConnect::scientistConnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistConnect)
{
    ui->setupUi(this);
    displayAllScientists();
    displayAllComputers();
}

scientistConnect::~scientistConnect()
{
    delete ui;
}

void scientistConnect::on_backButton_clicked()
{
    close();
}

void scientistConnect::on_connectButton_clicked()
{
    //setja inn koda fyrir tengingu scientist-comp
    close();
}

void scientistConnect::displayAllScientists()
{
    ui->sci_table->clearContents();
    currentScientists = scienceService.getAllScientists();
    ui->sci_table->setRowCount(currentScientists.size());
    currentlyDisplayedScientists.clear();
    for(unsigned int i = 0; i < currentScientists.size(); i++)
    {
        Scientist currentScientist = currentScientists[i];
        QString scientistID = QString::number(currentScientist.getId());
        QString scientistName = QString::fromStdString(currentScientist.getName());

        int currentRow = currentlyDisplayedScientists.size();

        ui->sci_table->setItem(currentRow, 0, new QTableWidgetItem(scientistID));
        ui->sci_table->setItem(currentRow, 1, new QTableWidgetItem(scientistName));

        currentlyDisplayedScientists.push_back(currentScientist);
    }
}


void scientistConnect::displayAllComputers()
{
    ui->comp_table->clearContents();
    currentComputers = scienceService.getAllComputers();
    ui->comp_table->setRowCount(currentComputers.size());
    currentlyDisplayedComputers.clear();
    for(unsigned int i = 0; i < currentComputers.size(); i++)
    {
        Computer currentComputer = currentComputers[i];
        QString computerID = QString::number(currentComputer.getId());
        QString computerName = QString::fromStdString(currentComputer.getName());

        int currentRow = currentlyDisplayedComputers.size();

        ui->comp_table->setItem(currentRow, 0, new QTableWidgetItem(computerID));
        ui->comp_table->setItem(currentRow, 1, new QTableWidgetItem(computerName));

        currentlyDisplayedComputers.push_back(currentComputer);
    }
}
