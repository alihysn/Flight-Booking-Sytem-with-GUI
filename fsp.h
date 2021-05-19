#ifndef FSP_H
#define FSP_H

#include <QDialog>

namespace Ui {
class fsp;
}

class fsp : public QDialog
{
    Q_OBJECT

public:
    explicit fsp(QWidget *parent = nullptr);
    ~fsp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::fsp *ui;
};

#endif // FSP_H
