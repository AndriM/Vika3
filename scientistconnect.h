#ifndef SCIENTISTCONNECT_H
#define SCIENTISTCONNECT_H

#include <QDialog>
#include <vector>
#include "scienceservice.h"
#include "computer.h"

namespace Ui {
class scientistConnect;
}

class scientistConnect : public QDialog
{
    Q_OBJECT
public:
    explicit scientistConnect(QWidget *parent = 0);
    ~scientistConnect();
    void displayAllScientists();
    void displayAllComputers();
private slots:
    void on_backButton_clicked();
    void on_connectButton_clicked();
private:
    Ui::scientistConnect *ui;
    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
};

#endif // SCIENTISTCONNECT_H
