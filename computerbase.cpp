#include "computerbase.h"
#include "ui_computerbase.h"

Computerbase::Computerbase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Computerbase)
{
    ui->setupUi(this);
    ui->searchLine->setPlaceholderText("Search computers...");
    scienceService = ScienceService();
    displayAllComputers();
}

Computerbase::~Computerbase()
{
    delete ui;
}

void Computerbase::on_addButton_clicked()
{
    ComputerAdd compAdd;
    compAdd.exec();
    displayAllComputers();
}

void Computerbase::on_button_disp_connected_clicked()
{
    DisplaySciConnection dispConn;
    dispConn.exec();
}

void Computerbase::on_button_connect_clicked()
{
    connection connect;
    connect.exec();
}

void Computerbase::on_backButton_clicked()
{
    close();
}

void Computerbase::getAllComputers()
{
    currentComputers = scienceService.getAllComputers();
}

void Computerbase::displayAllComputers()
{
    ui->listTable->clearContents();
    currentComputers = scienceService.getAllComputers();
    ui->listTable->setRowCount(currentComputers.size());
    currentlyDisplayedComputers.clear();

    for(unsigned int i = 0; i < currentComputers.size(); i++)
    {
        Computer currentComputer = currentComputers[i];
        std::string searchString = ui->searchLine->text().toStdString();

        if(currentComputer.contains(searchString))
        {
            QString ComputerName = QString::fromStdString(currentComputer.getName());
            QString ComputeryearBuilt = QString::fromStdString(currentComputer.getYearBuilt());
            QString Computertype = QString::fromStdString(currentComputer.getType());
            QString ComputerwasBuilt = QString::fromStdString(currentComputer.getWasBuilt());
            QString ComputerID = QString::number(currentComputer.getId());

            int currentRow = currentlyDisplayedComputers.size();

            ui->listTable->setItem(currentRow, 0, new QTableWidgetItem(ComputerName));
            ui->listTable->setItem(currentRow, 1, new QTableWidgetItem(Computertype));
            ui->listTable->setItem(currentRow, 2, new QTableWidgetItem(ComputerwasBuilt));
            ui->listTable->setItem(currentRow, 3, new QTableWidgetItem(ComputeryearBuilt));
            ui->listTable->setItem(currentRow, 4, new QTableWidgetItem((ComputerID)));
            currentlyDisplayedComputers.push_back(currentComputer);
        }
    }
    ui->listTable->setRowCount(currentlyDisplayedComputers.size());
}

void Computerbase::on_searchLine_textChanged(const QString &arg1)
{
    displayAllComputers();
}

void Computerbase::on_removeButton_clicked()
{
    int row = ui->listTable->currentRow();
    removeID = ui->listTable->item(row,4)->text().toInt();
    scienceService.removeComputer(removeID);
    displayAllComputers();
}
