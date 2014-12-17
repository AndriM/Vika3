#ifndef SCIENTISTADD_H
#define SCIENTISTADD_H

#include <QDialog>
#include <QFileDialog>
#include "scientist.h"
#include "scienceservice.h"
#include <QMessageBox>
#include <ctype.h>
#include <stdio.h>
#include <cctype>

namespace Ui {
class scientistadd;
}
//Adds scientists to the database
class scientistadd : public QDialog
{
    Q_OBJECT
public:
    explicit scientistadd(QWidget *parent = 0);
    ~scientistadd();
    Scientist getScientist();
    bool nameLineValid();
    bool yearOfBirthValid();
private slots:
    void on_nameLine_textChanged(const QString &arg1);
    void on_byLine_textChanged(const QString &arg1);
    void on_dyLine_textChanged(const QString &arg1);
    void on_addButton_clicked();
    void on_maleRadio_toggled(bool checked);
    void on_femaleRadio_toggled(bool checked);
    void on_checkBox_toggled(bool checked);
    void on_backButton_clicked();
    void on_photoButton_clicked();
private:
    ScienceService scienceService;
    Scientist newScientist;
    Ui::scientistadd *ui;
};

#endif // SCIENTISTADD_H
