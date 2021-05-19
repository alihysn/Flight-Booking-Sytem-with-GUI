#ifndef SFLIGHTS_H
#define SFLIGHTS_H

#include <QDialog>

namespace Ui {
class SFlights;
}

class SFlights : public QDialog
{
    Q_OBJECT

public:
    explicit SFlights(QWidget *parent = nullptr);
    ~SFlights();

private slots:
    void on_orderoflocation_clicked();

    void on_orderfordestination_clicked();

    void on_orderbyprice_clicked();

    void on_orderbyrating_clicked();

private:
    Ui::SFlights *ui;
};

#endif // SFLIGHTS_H
