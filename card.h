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
public:
    Card();
    bool Validity();
    int Pay();
};

#endif // CARD_H
