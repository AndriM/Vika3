#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include "scienceservice.h"
#include "computer.h"

namespace Ui {
class connection;
}

class connection : public QDialog
{
    Q_OBJECT
public:
    explicit connection(QWidget *parent = 0);
    ~connection();
    void displayAllScientists();
    void displayAllComputers();
private slots:
    void on_backButton_clicked();
    void on_connectButton_clicked();
private:
    Ui::connection *ui;
    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
};

#endif // CONNECTION_H
