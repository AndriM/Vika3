#include "connection.h"
#include "ui_connection.h"

connection::connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connection)
{
    ui->setupUi(this);
    displayAllComputers();
    displayAllScientists();
}

connection::~connection()
{
    delete ui;
}

void connection::on_backButton_clicked()
{
    close();
}

void connection::on_connectButton_clicked()
{
    //setja inn koda fyrir tengingu comp-scientist
    close();
}

void connection::displayAllScientists()
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


void connection::displayAllComputers()
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
