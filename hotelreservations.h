#ifndef HOTELRESERVATIONS_H
#define HOTELRESERVATIONS_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class hotelreservations; }
QT_END_NAMESPACE

class hotelreservations : public QMainWindow
{
    bool foundhotel;

public:
    hotelreservations(QWidget *parent = nullptr);
    ~hotelreservations();

private slots:
    void on_pushButton_clicked();

private:
    Ui::hotelreservations *ui;
};
#endif // HOTELRESERVATIONS_H
