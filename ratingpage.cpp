#include "ratingpage.h"
#include "ui_ratingpage.h"

RatingPage::RatingPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RatingPage)
{
    ui->setupUi(this);
}

RatingPage::~RatingPage()
{
    delete ui;
}

void RatingPage::on_pushButton_clicked()
{

}

void RatingPage::on_pushButton_2_clicked()
{

}
