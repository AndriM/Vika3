#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scientist.h"
#include "computer.h"
#include "computerbase.h"
#include "scientistbase.h"
#include "scienceservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addComp();
    void addScientist();

private slots:
    void on_pushButtonComputer_clicked();

    void on_pushButtonScientist_clicked();

private:
    ScienceService scienceService;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
