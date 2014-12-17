#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include "scienceservice.h"
#include "computer.h"

namespace Ui {
class connection;
}
//Links scientists to computers
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
    void on_comp_table_clicked(const QModelIndex &index);
    void on_sci_table_clicked(const QModelIndex &index);
private:
    Ui::connection *ui;
    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
    int currentIDcomputer;
    int currentIDscientist;
};

#endif // CONNECTION_H
