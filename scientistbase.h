#ifndef SCIENTISTBASE_H
#define SCIENTISTBASE_H

#include <QDialog>
#include "scientistadd.h"
#include "scientistconnect.h"
#include "displayconnection.h"
#include "scienceservice.h"
#include "displayscientist.h"
#include "removeconfirm.h"

namespace Ui {
class Scientistbase;
}
//Main window for scientists
class Scientistbase : public QDialog
{
    Q_OBJECT
public:
    explicit Scientistbase(QWidget *parent = 0);
    ~Scientistbase();
    Scientistbase SomethingFunction(QPoint &PosNafn);
private slots:
    void on_addButton_clicked();
    void on_button_connect_clicked();
    void on_button_disp_conn_clicked();
    void on_backButton_clicked();
    void displayAllScientists();
    void on_searchLine_textChanged(const QString &arg1);
    void on_listTable_doubleClicked(const QModelIndex &index);
    void on_removeButton_clicked();
private:
    Ui::Scientistbase *ui;
    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
    int removeID;
};

#endif // SCIENTISTBASE_H
