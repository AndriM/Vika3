#include "displayconnection.h"
#include "ui_displayconnection.h"

displayConnection::displayConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayConnection)
{
    ui->setupUi(this);
    displayAllComputers();
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
            QString ComputerName = QString::fromStdString(currentComputer.getName());
            QString ComputeryearBuilt = QString::fromStdString(currentComputer.getYearBuilt());
            QString Computertype = QString::fromStdString(currentComputer.getType());
            QString ComputerwasBuilt = QString::fromStdString(currentComputer.getWasBuilt());

            int currentRow = currentlyDisplayedComputers.size();

            ui->comp_table->setItem(currentRow, 0, new QTableWidgetItem(ComputerName));
            ui->comp_table->setItem(currentRow, 1, new QTableWidgetItem(Computertype));
            ui->comp_table->setItem(currentRow, 2, new QTableWidgetItem(ComputerwasBuilt));
            ui->comp_table->setItem(currentRow, 3, new QTableWidgetItem(ComputeryearBuilt));

            currentlyDisplayedComputers.push_back(currentComputer);
//        }
    }
    ui->comp_table->setRowCount(currentlyDisplayedComputers.size());
}
