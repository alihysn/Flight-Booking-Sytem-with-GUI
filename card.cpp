#include "card.h"
#include"paymentmethod.h"
#include"wallet.h"

Card::Card()
{

}
bool Card::Validity()
{
    int count = 0;
       while (PIN != 0)
       {
           PIN = PIN / 10;
           ++count;
       }
       int countNew=0;
       while (CardNumber!=0)
       {
           CardNumber=CardNumber/10;
           ++countNew;
       }

       if (count==3&&countNew==18)
          {
                   return true;

          }
}

void Card::Pay(Price CustomerPrice)
{
    if (Validity()==1)
    {
        Balance= Balance - CustomerPrice.getTotalPrice();
    }
}
