#ifndef WALLET_H
#define WALLET_H
#include"price.h"
#include"paymentmethod.h"

class Wallet: public Price
{
private:
    int Balance;
public:
    Wallet();
    void CheckBalance();
    int Pay();
    int Recharge();



};

#endif // WALLET_H
