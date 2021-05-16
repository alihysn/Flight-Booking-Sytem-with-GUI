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
    void on_pushButton_clicked();

private:
    Ui::SFlights *ui;
};

#endif // SFLIGHTS_H
