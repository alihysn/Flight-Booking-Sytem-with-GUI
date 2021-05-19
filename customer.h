#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"wallet.h"
#include <QMainWindow>
#include"trip.h"

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
    void readData(int id, QString nam, QString mail, QString userName,QString pass, QString pic, float wall, int pts, int numTrips);
    bool checker(QString userN, QString userP);
    QString getName();
    Customer* returnCust();
    void priceGetter();
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
    Trip currentTrip;
    Wallet CustomerWallet;
    Ui::Customer *ui;
};

#endif // CUSTOMER_H
