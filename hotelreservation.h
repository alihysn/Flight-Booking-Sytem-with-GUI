#ifndef HOTELRESERVATION_H
#define HOTELRESERVATION_H

#include <QMainWindow>

namespace Ui {
class hotelreservation;
}

class hotelreservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit hotelreservation(QWidget *parent = nullptr);
    ~hotelreservation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::hotelreservation *ui;
};

#endif // HOTELRESERVATION_H
