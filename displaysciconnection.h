#ifndef DISPLAYSCICONNECTION_H
#define DISPLAYSCICONNECTION_H

#include <QDialog>
#include "scientist.h"
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

private:
    Ui::DisplaySciConnection *ui;
    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
};

#endif // DISPLAYSCICONNECTION_H