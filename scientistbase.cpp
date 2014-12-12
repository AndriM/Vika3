#include "scientistbase.h"
#include "ui_scientistbase.h"

Scientistbase::Scientistbase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scientistbase)
{
    ui->setupUi(this);
}

Scientistbase::~Scientistbase()
{
    delete ui;
}

void Scientistbase::on_searchBar_textEdited(const QString &arg1)
{

}
