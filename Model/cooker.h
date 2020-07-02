#ifndef COOKER_H
#define COOKER_H
#include <Model/employee.h>
#include <Model/order.h>
class Cooker : virtual public Employee{
public:
    Cooker();
    Cooker* clone() const override;
    void setstateready(Order*);
};

#endif // COOKER_H
