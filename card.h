#ifndef CARD_H
#define CARD_H
#include"price.h"
#include "paymentmethod.h"
#include<QString>

class Card: public Price
{
private:
    int PIN;
    int CardNumber;
    int ExpiryMonth;
    int ExpiryDate;
    bool IsValid;
    int Balance=20000;
public:
    Card();
    bool Validity();
    void Pay(QString number,QString pin,QString from,QString expiry);
};

#endif // CARD_H
