#include "displaysciconnection.h"
#include "ui_displaysciconnection.h"
DisplaySciConnection::DisplaySciConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplaySciConnection)
{
    ui->setupUi(this);
    displayAllComputers();
    currentComputers = scienceService.getAllComputers();
}
DisplaySciConnection::~DisplaySciConnection()
{
    delete ui;
}
void DisplaySciConnection::displayConnectedScientists()
{
    ui->sci_table->clearContents();
    currentScientists = scienceService.connectedScientists(ID);
    ui->sci_table->setRowCount(currentScientists.size());
    currentlyDisplayedScientists.clear();
    for(unsigned int i = 0; i < currentScientists.size(); i++)
    {
        Scientist currentScientist = currentScientists[i];
        QString scientistName = QString::fromStdString(currentScientist.getName());
        int currentRow = currentlyDisplayedScientists.size();

        ui->sci_table->setItem(currentRow, 0, new QTableWidgetItem(scientistName));

        currentlyDisplayedScientists.push_back(currentScientist);

    }
    ui->sci_table->setRowCount(currentlyDisplayedScientists.size());
}
void DisplaySciConnection::on_backButton_clicked()
{
    close();
}
void DisplaySciConnection::on_pushButton_clicked()
{
    int row = ui->sci_table->currentRow();
    ID = ui->sci_table->item(row,0)->text().toInt();
    scienceService.connectedScientists(ID);
    displayConnectedScientists();
}
void DisplaySciConnection::displayAllComputers()
{
    ui->comp_table->clearContents();
    currentComputers = scienceService.getAllComputers();
    ui->comp_table->setRowCount(currentComputers.size());
    currentlyDisplayedComputers.clear();
    for(unsigned int i = 0; i < currentComputers.size(); i++)
    {
        Computer currentComputer = currentComputers[i];

            QString ComputerID = QString::number(currentComputer.getId());
            QString ComputerName = QString::fromStdString(currentComputer.getName());

            int currentRow = currentlyDisplayedComputers.size();
            ui->comp_table->setItem(currentRow, 0, new QTableWidgetItem(ComputerID));
            ui->comp_table->setItem(currentRow, 1, new QTableWidgetItem(ComputerName));

            currentlyDisplayedComputers.push_back(currentComputer);
    }
    ui->comp_table->setRowCount(currentlyDisplayedComputers.size());
}
