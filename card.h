#ifndef CARD_H
#define CARD_H
#include"price.h"
#include "paymentmethod.h"

class Card: public Price
{
private:
    int PIN;
    int CardNumber;
    int ExpiryMonth;
    int ExpiryDate;
    bool IsValid;
    int Balance;
public:
    Card();
    bool Validity();
    void Pay(Price CustomerPrice);

};

#endif // CARD_H
