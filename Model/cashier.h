#ifndef CASHIER_H
#define CASHIER_H
#include <Model/employee.h>
#include <Model/order.h>
class Cashier : virtual public Employee{
public:
    Cashier();
    Cashier* clone() const override;
    bool ordercomplete(Order*i);
};

#endif // CASHIER_H
