#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H
#include"price.h"


class PaymentMethod
{
private:

public:
    PaymentMethod();
    virtual int Pay( Price * Currprice)=0;

};
#endif // PAYMENTMETHOD_H
