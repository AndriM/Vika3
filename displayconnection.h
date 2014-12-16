#ifndef DISPLAYCONNECTION_H
#define DISPLAYCONNECTION_H

#include <QDialog>
#include "computer.h"
#include "scienceservice.h"

namespace Ui {
class displayConnection;
}

class displayConnection : public QDialog
{
    Q_OBJECT
public:
    explicit displayConnection(QWidget *parent = 0);
    ~displayConnection();
private slots:
    void on_backButton_clicked();
private:
    void displayAllComputers();
    ScienceService scienceService;
    Ui::displayConnection *ui;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
};

#endif // DISPLAYCONNECTION_H
