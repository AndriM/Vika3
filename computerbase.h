#ifndef COMPUTERBASE_H
#define COMPUTERBASE_H

#include <QDialog>
#include "computeradd.h"
#include "displaysciconnection.h"
#include "connection.h"
#include "scienceservice.h"
#include "computer.h"
#include "removeconfirm.h"

namespace Ui {
class Computerbase;
}
//Main window for computers
class Computerbase : public QDialog
{
    Q_OBJECT
public:
    explicit Computerbase(QWidget *parent = 0);
    ~Computerbase();
private slots:
    void on_addButton_clicked();
    void on_button_disp_connected_clicked();
    void on_button_connect_clicked();
    void on_backButton_clicked();
    void on_searchLine_textChanged(const QString &arg1);
    void on_removeButton_clicked();
private:
    Ui::Computerbase *ui;
    void getAllComputers();
    void displayAllComputers();

    ScienceService scienceService;
    std::vector<Computer> currentComputers;
    std::vector<Computer> currentlyDisplayedComputers;
    int removeID;
};

#endif // COMPUTERBASE_H
