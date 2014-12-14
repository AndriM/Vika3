#ifndef SCIENTISTBASE_H
#define SCIENTISTBASE_H

#include <QDialog>
#include "scientistadd.h"

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
    void on_searchBar_textEdited(const QString &arg1);

    void on_addButton_clicked();

private:
    Ui::Scientistbase *ui;
};

#endif // SCIENTISTBASE_H
