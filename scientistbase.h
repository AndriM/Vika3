#ifndef SCIENTISTBASE_H
#define SCIENTISTBASE_H

#include <QDialog>
#include "scientistadd.h"
#include "scientistconnect.h"
#include "displayconnection.h"
#include "scienceservice.h"

namespace Ui {
class Scientistbase;
}

class Scientistbase : public QDialog
{
    Q_OBJECT
public:
    explicit Scientistbase(QWidget *parent = 0);
    ~Scientistbase();
private slots:
    void on_addButton_clicked();
    void on_button_connect_clicked();
    void on_button_disp_conn_clicked();
    void on_backButton_clicked();
    void displayAllScientists();
    void on_searchLine_textChanged(const QString &arg1);
private:
    Ui::Scientistbase *ui;
    ScienceService scienceService;
    std::vector<Scientist> currentScientists;
    std::vector<Scientist> currentlyDisplayedScientists;
};

#endif // SCIENTISTBASE_H
