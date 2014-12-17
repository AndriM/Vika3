#include "displayconnection.h"
#include "ui_displayconnection.h"

displayConnection::displayConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayConnection)
{
    ui->setupUi(this);
    displayAllScientists();
    currentScientists = scienceService.getAllScientists();
}

displayConnection::~displayConnection()
{
    delete ui;
}

void displayConnection::on_backButton_clicked()
{
    close();
}

void displayConnection::displayConnectedComputers()
{
    ui->comp_table->clearContents();
    currentComputers = scienceService.connectedComputers(ID);
    ui->comp_table->setRowCount(currentComputers.size());
    currentlyDisplayedComputers.clear();
    for(unsigned int i = 0; i < currentComputers.size(); i++)
    {
        Computer currentComputer = currentComputers[i];
            QString ComputerName = QString::fromStdString(currentComputer.getName());
            int currentRow = currentlyDisplayedComputers.size();
            ui->comp_table->setItem(currentRow, 0, new QTableWidgetItem(ComputerName));
            currentlyDisplayedComputers.push_back(currentComputer);
    }

    ui->comp_table->setRowCount(currentlyDisplayedComputers.size());
}

void displayConnection::on_displayButton_clicked()
{
    int row = ui->sci_table->currentRow();
    ID = ui->sci_table->item(row,0)->text().toInt();
    scienceService.connectedComputers(ID);
    displayConnectedComputers();
}

void displayConnection::displayAllScientists()
{
    ui->sci_table->clearContents();
    currentScientists = scienceService.getAllScientists();
    ui->sci_table->setRowCount(currentScientists.size());
    currentlyDisplayedScientists.clear();
    for(unsigned int i = 0; i < currentScientists.size(); i++)
    {
        Scientist currentScientist = currentScientists[i];

            QString ScientistID = QString::number(currentScientist.getId());
            QString ScientistName = QString::fromStdString(currentScientist.getName());

            int currentRow = currentlyDisplayedScientists.size();
            ui->sci_table->setItem(currentRow, 0, new QTableWidgetItem(ScientistID));
            ui->sci_table->setItem(currentRow, 1, new QTableWidgetItem(ScientistName));

            currentlyDisplayedScientists.push_back(currentScientist);
    }
    ui->sci_table->setRowCount(currentlyDisplayedScientists.size());
}
