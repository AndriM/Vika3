#ifndef SCIENTISTADD_H
#define SCIENTISTADD_H

#include <QDialog>
#include "scientist.h"

namespace Ui {
class scientistadd;
}

class scientistadd : public QDialog
{
    Q_OBJECT

public:
    explicit scientistadd(QWidget *parent = 0);
    ~scientistadd();
    Scientist getScientist();

private slots:

    void on_nameLine_textChanged(const QString &arg1);

    void on_byLine_textChanged(const QString &arg1);

    void on_dyLine_textChanged(const QString &arg1);

    void on_addButton_clicked();

    void on_maleRadio_toggled(bool checked);

    void on_femaleRadio_toggled(bool checked);

    void on_checkBox_toggled(bool checked);

    void on_backButton_clicked();

private:
    Scientist newScientist;
    Ui::scientistadd *ui;
};

#endif // SCIENTISTADD_H
