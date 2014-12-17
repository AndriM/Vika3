#ifndef REMOVECONFIRM_H
#define REMOVECONFIRM_H

#include <QDialog>
#include "scienceservice.h"

namespace Ui {
class RemoveConfirm;
}

class RemoveConfirm : public QDialog
{
    Q_OBJECT
public:
    explicit RemoveConfirm(QWidget *parent = 0);
    ~RemoveConfirm();
    bool button;
private slots:
    void on_yes_button_clicked();
    void on_no_button_clicked();
private:
    Ui::RemoveConfirm *ui;
    ScienceService scienceService;
};

#endif // REMOVECONFIRM_H
