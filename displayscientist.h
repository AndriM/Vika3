#ifndef DISPLAYSCIENTIST_H
#define DISPLAYSCIENTIST_H

#include <QDialog>
#include <QPixmap>
#include "scientist.h"

namespace Ui {
class displayScientist;
}
//popup window from scientists main window -> shows more information (photo)
class displayScientist : public QDialog
{
    Q_OBJECT
public:
    explicit displayScientist(QWidget *parent = 0);
    ~displayScientist();
    void displayPhoto(Scientist scientist);
private slots:
    void on_pushButton_clicked();
private:
    Ui::displayScientist *ui;
    Scientist newscientist;
};

#endif // DISPLAYSCIENTIST_H
