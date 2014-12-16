#include "displaysciconnection.h"
#include "ui_displaysciconnection.h"


DisplaySciConnection::DisplaySciConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplaySciConnection)
{
    ui->setupUi(this);
    displayAllScientists();
    currentComputers = scienceService.getAllComputers();
}

DisplaySciConnection::~DisplaySciConnection()
{
    delete ui;
}

void DisplaySciConnection::displayAllScientists()
{
    ui->sci_table->clearContents();
    currentScientists = scienceService.getAllScientists();
    ui->sci_table->setRowCount(currentScientists.size());
    currentlyDisplayedScientists.clear();

    for(unsigned int i = 0; i < currentScientists.size(); i++)
    {
        Scientist currentScientist = currentScientists[i];
//        std::string searchString = ui->searchLine->text().toStdString();

//        if(currentComputer.contains(searchString))
//        {
        QString scientistID = QString::number(currentScientist.getId());
        QString scientistName = QString::fromStdString(currentScientist.getName());
//        QString scientistDateOfDeath = QString::fromStdString(currentScientist.getDateOfDeath());
//        QString scientistGender = QString::fromStdString(currentScientist.getGender());

        int currentRow = currentlyDisplayedScientists.size();

        ui->sci_table->setItem(currentRow, 0, new QTableWidgetItem(scientistID));
        ui->sci_table->setItem(currentRow, 1, new QTableWidgetItem(scientistName));
//        ui->sci_table->setItem(currentRow, 2, new QTableWidgetItem(scientistDateOfDeath));
//        ui->sci_table->setItem(currentRow, 3, new QTableWidgetItem(scientistGender));

        currentlyDisplayedScientists.push_back(currentScientist);
//        }
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
    scienceService.connectedComputers(ID);
    displayConnectedComputers();
}
void DisplaySciConnection::displayConnectedComputers()
{
    ui->comp_table->clearContents();
    currentComputers = scienceService.connectedComputers(ID);
    ui->comp_table->setRowCount(currentComputers.size());
    currentlyDisplayedComputers.clear();

    for(unsigned int i = 0; i < currentComputers.size(); i++)
    {
        Computer currentComputer = currentComputers[i];
//        std::string searchString = ui->searchLine->text().toStdString();

        //if(currentScientist.contains(ID))
        //{
            QString ComputerName = QString::fromStdString(currentComputer.getName());
//            QString ComputeryearBuilt = QString::fromStdString(currentComputer.getYearBuilt());
//            QString Computertype = QString::fromStdString(currentComputer.getType());
//            QString ComputerwasBuilt = QString::fromStdString(currentComputer.getWasBuilt());

            int currentRow = currentlyDisplayedComputers.size();

            ui->comp_table->setItem(currentRow, 0, new QTableWidgetItem(ComputerName));
//            ui->sci_table->setItem(currentRow, 1, new QTableWidgetItem(Computertype));
//            ui->sci_table->setItem(currentRow, 2, new QTableWidgetItem(ComputerwasBuilt));
//            ui->sci_table->setItem(currentRow, 3, new QTableWidgetItem(ComputeryearBuilt));

            currentlyDisplayedComputers.push_back(currentComputer);
        //}
    }
    ui->comp_table->setRowCount(currentlyDisplayedComputers.size());
}
