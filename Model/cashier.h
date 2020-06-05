#ifndef CASHIER_H
#define CASHIER_H
#include <Model/employee.h>

class Cashier : virtual public Employee{
public:
    Cashier();
    Cashier* clone() const override;
};

#endif // CASHIER_H
