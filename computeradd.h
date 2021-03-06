#ifndef COMPUTERADD_H
#define COMPUTERADD_H

#include "computer.h"
#include "scienceservice.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ComputerAdd;
}
//Adds computers to the database
class ComputerAdd : public QDialog
{
    Q_OBJECT
public:
    explicit ComputerAdd(QWidget *parent = 0);
    ~ComputerAdd();
    Computer getComputer();
    bool typeValid();
    bool nameLineValid();
    bool buildFieldValid();
private slots:
    void on_compname_textChanged(const QString &arg1);
    void on_comptype_textChanged(const QString &arg1);
    void on_yearLine_textChanged(const QString &arg1);
    void on_addButton_clicked();
    void on_back_clicked();
    void on_builtno_toggled(bool checked);
    void on_builtyes_clicked();
private:
    Ui::ComputerAdd *ui;
    Computer newComputer;
    ScienceService scienceService;
    bool yes;
    bool no;
};

#endif // COMPUTERADD_H
