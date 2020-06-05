#include "cooker.h"

Cooker::Cooker()
{

}
Cooker* Cooker::clone()const{
    return new Cooker(*this);
}

