#include "scientistconnect.h"
#include "ui_scientistconnect.h"

scientistConnect::scientistConnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistConnect)
{
    ui->setupUi(this);
    displayAllScientists();
    displayAllComputers();
    currentIDcomputer = 0;
    currentIDscientist = 0;
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
    scienceService.connectScientists(currentIDscientist,currentIDcomputer);
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


void scientistConnect::on_sci_table_clicked(const QModelIndex &index)
{
    int row = ui->sci_table->currentRow();
    currentIDscientist = ui->sci_table->item(row,0)->text().toInt();
}

void scientistConnect::on_comp_table_clicked(const QModelIndex &index)
{
    int row = ui->comp_table->currentRow();
    currentIDcomputer = ui->comp_table->item(row,0)->text().toInt();
}
