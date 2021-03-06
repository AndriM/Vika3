#include "scientistbase.h"
#include "ui_scientistbase.h"
#include <QDebug>

Scientistbase::Scientistbase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scientistbase)
{
    ui->setupUi(this);
    ui->searchLine->setPlaceholderText("Search scientists...");
    displayAllScientists();
}

Scientistbase::~Scientistbase()
{
    delete ui;
}

void Scientistbase::on_addButton_clicked()
{
    scientistadd sciAdd;
    sciAdd.exec();
    displayAllScientists();
}

void Scientistbase::on_button_connect_clicked()
{
    scientistConnect connect;
    connect.exec();
}

void Scientistbase::on_backButton_clicked()
{
    close();
}

void Scientistbase::displayAllScientists()
{
    ui->listTable->clearContents();
    currentScientists = scienceService.getAllScientists();
    ui->listTable->setRowCount(currentScientists.size());
    currentlyDisplayedScientists.clear();

    for(unsigned int i = 0; i < currentScientists.size(); i++)
    {
        Scientist currentScientist = currentScientists[i];
        std::string searchString = ui->searchLine->text().toStdString();

        if(currentScientist.contains(searchString))
        {
            QString scientistName = QString::fromStdString(currentScientist.getName());
            QString scientistDateOfBirth = QString::fromStdString(currentScientist.getDateOfBirth());
            QString scientistDateOfDeath = QString::fromStdString(currentScientist.getDateOfDeath());
            QString scientistGender = QString::fromStdString(currentScientist.getGender());
            QString scientistID = QString::number(currentScientist.getId());
            int currentRow = currentlyDisplayedScientists.size();

            ui->listTable->setItem(currentRow, 0, new QTableWidgetItem(scientistName));
            ui->listTable->setItem(currentRow, 1, new QTableWidgetItem(scientistDateOfBirth));
            ui->listTable->setItem(currentRow, 2, new QTableWidgetItem(scientistDateOfDeath));
            ui->listTable->setItem(currentRow, 3, new QTableWidgetItem(scientistGender));
            ui->listTable->setItem(currentRow, 4, new QTableWidgetItem(scientistID));

            currentlyDisplayedScientists.push_back(currentScientist);
        }
    }
    ui->listTable->setRowCount(currentlyDisplayedScientists.size());
}

void Scientistbase::on_searchLine_textChanged(const QString &arg1)
{
    displayAllScientists();
}

void Scientistbase::on_listTable_doubleClicked(const QModelIndex &index)
{
    displayScientist display;
    display.displayPhoto(currentScientists[index.row()]);
    display.exec();
}

void Scientistbase::on_removeButton_clicked()
{
    int row = ui->listTable->currentRow();
    removeID = ui->listTable->item(row,4)->text().toInt();

    RemoveConfirm remove;
    remove.exec();

    if(remove.button == true)
    {
        scienceService.removeScientist(removeID);
        displayAllScientists();
    }
}

void Scientistbase::on_button_disp_conn_clicked()
{
    displayConnection dc;
    dc.exec();
}
