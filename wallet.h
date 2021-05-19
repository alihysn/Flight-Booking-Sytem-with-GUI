#ifndef WALLET_H
#define WALLET_H
#include"price.h"
#include"paymentmethod.h"

class Wallet: public Price
{
private:
    int Balance=20000;
public:
    Wallet();
    void CheckBalance();
    void Pay(Price CustomerPrice);
    void Recharge();
    int getBalance();


};


#endif // WALLET_H
