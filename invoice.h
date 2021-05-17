#ifndef INVOICE_H
#define INVOICE_H
#include "customer.h"

class Invoice
{
public:
    Invoice();

    void ShowInvoice(Customer *currentCustomer);
};

#endif // INVOICE_H
