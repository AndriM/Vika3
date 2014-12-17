#ifndef DISPLAYSCICONNECTION_H
#define DISPLAYSCICONNECTION_H

#include <QDialog>
#include "scientist.h"
#include "computer.h"
#include "scienceservice.h"

namespace Ui {
class DisplaySciConnection;
}
//Displays the connection between computers and scientists
class DisplaySciConnection : public QDialog
{
    Q_OBJECT
public:
    explicit DisplaySciConnection(QWidget *parent = 0);
    ~DisplaySciConnection();
    void displayAllComputers();
    void displayConnectedScientists();
private slots:
    void on_backButton_clicked();
    void on_pushButton_clicked();
private:
    Ui::DisplaySciConnection *ui;
    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
    int ID;
};
#endif // DISPLAYSCICONNECTION_H
