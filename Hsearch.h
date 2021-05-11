#ifndef HSEARCH_H
#define HSEARCH_H

#include <QDialog>

namespace Ui {
class Hsearch;
}

class Hsearch : public QDialog
{
    Q_OBJECT

public:
    explicit Hsearch(QWidget *parent = nullptr);
    ~Hsearch();

private:
    Ui::Hsearch *ui;
};

#endif // HSEARCH_H
