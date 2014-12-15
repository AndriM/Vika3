#ifndef COMPUTERCONNECT_H
#define COMPUTERCONNECT_H

#include <QDialog>
#include <vector>
#include "scienceservice.h"
#include "computer.h"

namespace Ui {
class computerconnect;
}

class computerconnect : public QDialog
{
    Q_OBJECT

public:
    explicit computerconnect(QWidget *parent = 0);
    ~computerconnect();

    void displayAllComputers();
    void displayAllScientists();
private slots:
    void on_buttonConnect_clicked();

    void on_buttonBackFromConnect_clicked();

private:
    Ui::scientistConnect *ui;

    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
};

#endif // COMPUTERCONNECT_H
