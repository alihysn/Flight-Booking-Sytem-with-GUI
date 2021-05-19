#ifndef CREDITPAY_H
#define CREDITPAY_H

#include <QMainWindow>

namespace Ui {
class creditPay;
}

class creditPay : public QMainWindow
{
    Q_OBJECT

public:
    explicit creditPay(QWidget *parent = nullptr);
    ~creditPay();

private slots:
    void on_pushButton_clicked();

private:
    Ui::creditPay *ui;
};

#endif // CREDITPAY_H
