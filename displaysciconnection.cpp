#include "displaysciconnection.h"
#include "ui_displaysciconnection.h"

DisplaySciConnection::DisplaySciConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplaySciConnection)
{
    ui->setupUi(this);
    displayAllScientists();
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
        QString scientistName = QString::fromStdString(currentScientist.getName());
        QString scientistDateOfBirth = QString::fromStdString(currentScientist.getDateOfBirth());
        QString scientistDateOfDeath = QString::fromStdString(currentScientist.getDateOfDeath());
        QString scientistGender = QString::fromStdString(currentScientist.getGender());

        int currentRow = currentlyDisplayedScientists.size();

        ui->sci_table->setItem(currentRow, 0, new QTableWidgetItem(scientistName));
        ui->sci_table->setItem(currentRow, 1, new QTableWidgetItem(scientistDateOfBirth));
        ui->sci_table->setItem(currentRow, 2, new QTableWidgetItem(scientistDateOfDeath));
        ui->sci_table->setItem(currentRow, 3, new QTableWidgetItem(scientistGender));

        currentlyDisplayedScientists.push_back(currentScientist);
//        }
    }
    ui->sci_table->setRowCount(currentlyDisplayedScientists.size());
}

void DisplaySciConnection::on_backButton_clicked()
{
    close();
}
