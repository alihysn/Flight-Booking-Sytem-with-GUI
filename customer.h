#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QMainWindow>

namespace Ui {
class Customer;
}

class Customer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Customer(QWidget *parent = nullptr);
    void setProfile(QString name, QString currEmail, QString currUsername, QString passKey);
    void setPhotoPath(QString path);
    ~Customer();

private slots:
    void on_createButton_clicked();

    void on_photoButton_clicked();

    void on_showPassKey_clicked();

private:
    QString username;
    QString name;
    QString password;
    int id;
    QString email;
    QString photo;
    float walletMoney;
    int points;
    int NumberOfTrips;
    //Trip currentTrip
    Ui::Customer *ui;
};

#endif // CUSTOMER_H
