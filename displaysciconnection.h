#ifndef DISPLAYSCICONNECTION_H
#define DISPLAYSCICONNECTION_H

#include <QDialog>
#include "scientist.h"
#include "computer.h"
#include "scienceservice.h"

namespace Ui {
class DisplaySciConnection;
}

class DisplaySciConnection : public QDialog
{
    Q_OBJECT

public:
    explicit DisplaySciConnection(QWidget *parent = 0);
    ~DisplaySciConnection();    
    void displayAllScientists();
private slots:
    void on_backButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::DisplaySciConnection *ui;
    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
    int compID;

};

#endif // DISPLAYSCICONNECTION_H
