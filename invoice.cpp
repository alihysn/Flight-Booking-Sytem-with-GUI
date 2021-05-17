#include "invoice.h"
#include"customer.h"
#include<QMessageBox>

Invoice::Invoice()
{

}

void Invoice::ShowInvoice(Customer *currentCustomer)
{
    QMessageBox box;
    box.setText(currentCustomer->getName());
    box.setWindowTitle("User name:");
    box.exec();
    currentCustomer->priceGetter();
}
