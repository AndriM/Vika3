#ifndef DISPLAYSCIENTIST_H
#define DISPLAYSCIENTIST_H

#include <QDialog>
#include <QPixmap>
#include "scientist.h"

namespace Ui {
class displayScientist;
}

class displayScientist : public QDialog
{
    Q_OBJECT

public:
    explicit displayScientist(QWidget *parent = 0);
    ~displayScientist();
    void displayPhoto(Scientist scientist);

private:
    Ui::displayScientist *ui;
    Scientist newscientist;
};

#endif // DISPLAYSCIENTIST_H
