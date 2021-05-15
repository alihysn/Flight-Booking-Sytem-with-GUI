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
    void on_radioButton_toggled(bool checked);

private:
    Ui::SFlights *ui;
};

#endif // SFLIGHTS_H
