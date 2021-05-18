#ifndef HSEARCH_H
#define HSEARCH_H

#include <QDialog>

namespace Ui {
class Hsearch;
}

class Hsearch : public QDialog
{
    Q_OBJECT

public:
    explicit Hsearch(QWidget *parent = nullptr);
    ~Hsearch();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Hsearch *ui;
};

#endif // HSEARCH_H
