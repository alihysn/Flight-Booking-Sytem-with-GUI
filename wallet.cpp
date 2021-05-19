#include"wallet.h"
#include"price.h"
#include"paymentmethod.h"
#include <QMessageBox>

Wallet::Wallet()
{

}
void Wallet:: Pay(Price CustomerPrice)
{
    if ( Balance > CustomerPrice.getTotalPrice())
        Balance = Balance - CustomerPrice.getTotalPrice();

}

int Wallet::getBalance()
{
    return Balance;
}

void Wallet:: Recharge()
{

}

void Wallet:: CheckBalance()
{




}

