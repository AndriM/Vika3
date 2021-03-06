#ifndef DISPLAYCONNECTION_H
#define DISPLAYCONNECTION_H

#include <QDialog>
#include "computer.h"
#include "scientist.h"
#include "scienceservice.h"

namespace Ui {
class displayConnection;
}
//Displays the connection between scientists and computers
class displayConnection : public QDialog
{
    Q_OBJECT
public:
    explicit displayConnection(QWidget *parent = 0);
    ~displayConnection();
    void displayConnectedComputers();
    void displayAllScientists();
private slots:
    void on_backButton_clicked();
    void on_displayButton_clicked();
private:
    ScienceService scienceService;
    Ui::displayConnection *ui;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
    int ID;
};
#endif // DISPLAYCONNECTION_H
