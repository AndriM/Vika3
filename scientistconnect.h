#ifndef SCIENTISTCONNECT_H
#define SCIENTISTCONNECT_H

#include <QDialog>
#include <QTableWidget>
#include <vector>
#include "scienceservice.h"
#include "computer.h"

namespace Ui {
class scientistConnect;
}
//Link computers to scientists
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
    void on_sci_table_clicked(const QModelIndex &index);
    void on_comp_table_clicked(const QModelIndex &index);
private:
    Ui::scientistConnect *ui;
    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
    int currentIDcomputer;
    int currentIDscientist;
};

#endif // SCIENTISTCONNECT_H
