#include "ratingpage.h"
#include "ui_ratingpage.h"
#include <QInputDialog>
#include <QString>
#include "rating.h"
using namespace std;
RatingPage::RatingPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RatingPage)
{
    ui->setupUi(this);
    ui->label->setText(" ");
    ui->label_2->setText (" ");
}
Rating R;
RatingPage::~RatingPage()
{
    delete ui;
}

void RatingPage::on_pushButton_clicked()
{
int n= QInputDialog::getInt(this,"enter", " enter a number between 0 and 5");
ui->label->setText(QString::number (n));
R.rateflight(n);
}

void RatingPage::on_pushButton_2_clicked()
{
int n= QInputDialog::getInt(this, "enter", " enter a number between 0 and 5");
ui->label_2->setText(QString::number (n));
R.ratehotel(n);
}

