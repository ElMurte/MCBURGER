#ifndef MANAGER_H
#define MANAGER_H
#include"Model/cashier.h"
#include"Model/cooker.h"

class Manager : public Cashier, public Cooker{
public:
    Manager();
    Manager *clone()const override;
};

#endif // MANAGER_H
