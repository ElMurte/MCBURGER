#ifndef COOKER_H
#define COOKER_H
#include <Model/employee.h>

class Cooker : virtual public Employee{
public:
    Cooker();
    Cooker* clone() const override;
};

#endif // COOKER_H
