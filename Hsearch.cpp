#include "Hsearch.h"
#include "ui_Hsearch.h"

Hsearch::Hsearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hsearch)
{
    ui->setupUi(this);
}

Hsearch::~Hsearch()
{
    delete ui;
}
