#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QMainWindow>

namespace Ui {
class editProfile;
}

class editProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit editProfile(QWidget *parent = nullptr);
    ~editProfile();

private:
    Ui::editProfile *ui;
};

#endif // EDITPROFILE_H
