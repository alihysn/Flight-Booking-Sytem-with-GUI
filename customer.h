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
    void setProfile(QString name, QString currEmail);
    void setPhotoPath(QString path);
    ~Customer();

private slots:
    void on_createButton_clicked();

    void on_photoButton_clicked();

private:
    QString name;
    int id;
    QString email;
    QString photo;
    int points;
    int NumberOfTrips;
    //Trip currentTrip
    Ui::Customer *ui;
};

#endif // CUSTOMER_H
