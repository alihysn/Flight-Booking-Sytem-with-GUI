#ifndef RATINGPAGE_H
#define RATINGPAGE_H

#include <QDialog>

namespace Ui {
class RatingPage;
}

class RatingPage : public QDialog
{
    Q_OBJECT

public:
    explicit RatingPage(QWidget *parent = nullptr);
    ~RatingPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::RatingPage *ui;
};

#endif // RATINGPAGE_H
