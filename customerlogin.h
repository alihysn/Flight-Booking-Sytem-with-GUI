#ifndef CUSTOMERLOGIN_H
#define CUSTOMERLOGIN_H

#include <QMainWindow>
#include "customer.h"

namespace Ui {
class CustomerLogin;
}

class CustomerLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerLogin(QWidget *parent = nullptr);
    void startWindow(QVector<Customer*> custs, int *ind, bool *isLoggedIN);
    ~CustomerLogin();

private slots:
    void on_loginButton_clicked();

    void on_showP_clicked();

private:
    Ui::CustomerLogin *ui;
    QVector <Customer*> currData;
    Customer *cust;
    bool *loggedIn;
    int *number;
};

#endif // CUSTOMERLOGIN_H
