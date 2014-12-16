#include "displaysciconnection.h"
#include "ui_displaysciconnection.h"


DisplaySciConnection::DisplaySciConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplaySciConnection)
{
    ui->setupUi(this);
    displayAllScientists();
    currentComputers = scienceService.getAllComputers();
    for(unsigned int i = 0; i < currentComputers.size(); i++)
    {
        Computer currentComputer = currentComputers[i];
        ui->comboBox->addItem(QString::fromStdString(currentComputer.getName()));
       // ui->comboBox->itemData(0, )
    }
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

void DisplaySciConnection::on_comboBox_activated(const QString &arg1)
{

}

void DisplaySciConnection::on_comboBox_currentTextChanged(const QString &arg1)
{
//    Computer currentComputer;
//    currentComputers = scienceService.getAllComputers();
//    //for(unsigned int i = 0; i < currentComputers.size(); i++)
//    //{
//        //Computer currentComputer = currentComputers[i];
//        //compID = ui->comboBox->property(QString::number(currentComputer.getId()));
//        //ui->comboBox->addItem(QString::fromStdString(currentComputer.getName()));
//        compID = ui->comboBox->property(currentComputer.getId()).toInt();
//        scienceService.connectedComputers(compID);
//    //}
}

void DisplaySciConnection::on_comboBox_currentIndexChanged(int index)
{
//    Computer currentComputer;
//    currentComputers = scienceService.getAllComputers();
//    for(unsigned int i = 0; i < currentComputers.size(); i++)
//    {
//        Computer currentComputer = currentComputers[i];
//        compID = ui->comboBox->currentData(currentComputer.getId());
//        scienceService.connectedComputers(compID);
//    }
}
