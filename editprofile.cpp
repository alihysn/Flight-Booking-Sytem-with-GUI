#include "editprofile.h"
#include "ui_editprofile.h"

editProfile::editProfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editProfile)
{
    ui->setupUi(this);
}

editProfile::~editProfile()
{
    delete ui;
}
