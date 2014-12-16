#include "displayconnection.h"
#include "ui_displayconnection.h"

displayConnection::displayConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayConnection)
{
    ui->setupUi(this);
    displayAllComputers();
    currentScientists = scienceService.getAllScientists();
//    for(unsigned int i = 0; i < currentScientists.size(); i++)
//    {
//        Scientist currentScientist = currentScientists[i];
//        ui->comboBox->addItem(QString::fromStdString(currentScientist.getName()));
//    }
}

displayConnection::~displayConnection()
{
    delete ui;
}

void displayConnection::on_backButton_clicked()
{
    close();
}

void displayConnection::displayAllComputers()
{
    ui->comp_table->clearContents();
    currentComputers = scienceService.getAllComputers();
    ui->comp_table->setRowCount(currentComputers.size());
    currentlyDisplayedComputers.clear();

    for(unsigned int i = 0; i < currentComputers.size(); i++)
    {
        Computer currentComputer = currentComputers[i];
//        std::string searchString = ui->searchLine->text().toStdString();

//        if(currentComputer.contains(searchString))
//        {
            QString ComputerID = QString::number(currentComputer.getId());
            QString ComputerName = QString::fromStdString(currentComputer.getName());
//            QString Computertype = QString::fromStdString(currentComputer.getType());
//            QString ComputerwasBuilt = QString::fromStdString(currentComputer.getWasBuilt());

            int currentRow = currentlyDisplayedComputers.size();

            ui->comp_table->setItem(currentRow, 0, new QTableWidgetItem(ComputerID));
            ui->comp_table->setItem(currentRow, 1, new QTableWidgetItem(ComputerName));
//            ui->comp_table->setItem(currentRow, 2, new QTableWidgetItem(ComputerwasBuilt));
//            ui->comp_table->setItem(currentRow, 3, new QTableWidgetItem(ComputeryearBuilt));

            currentlyDisplayedComputers.push_back(currentComputer);
//        }
    }
    ui->comp_table->setRowCount(currentlyDisplayedComputers.size());
}

void displayConnection::on_displayButton_clicked()
{
    int row = ui->comp_table->currentRow();
    ID = ui->comp_table->item(row,0)->text().toInt();
    scienceService.connectedScientists(ID);
    displayConnectedScientists();
}

void displayConnection::displayConnectedScientists()
{
    ui->sci_table->clearContents();
    currentScientists = scienceService.connectedScientists(ID);
    ui->sci_table->setRowCount(currentScientists.size());
    currentlyDisplayedScientists.clear();

    for(unsigned int i = 0; i < currentScientists.size(); i++)
    {
        Scientist currentScientist = currentScientists[i];
//        std::string searchString = ui->searchLine->text().toStdString();

        //if(currentScientist.contains(ID))
        //{
            QString ScientistName = QString::fromStdString(currentScientist.getName());
//            QString ComputeryearBuilt = QString::fromStdString(currentComputer.getYearBuilt());
//            QString Computertype = QString::fromStdString(currentComputer.getType());
//            QString ComputerwasBuilt = QString::fromStdString(currentComputer.getWasBuilt());

            int currentRow = currentlyDisplayedScientists.size();

            ui->sci_table->setItem(currentRow, 0, new QTableWidgetItem(ScientistName));
//            ui->sci_table->setItem(currentRow, 1, new QTableWidgetItem(Computertype));
//            ui->sci_table->setItem(currentRow, 2, new QTableWidgetItem(ComputerwasBuilt));
//            ui->sci_table->setItem(currentRow, 3, new QTableWidgetItem(ComputeryearBuilt));

            currentlyDisplayedScientists.push_back(currentScientist);
        //}
    }
    ui->sci_table->setRowCount(currentlyDisplayedComputers.size());
}
