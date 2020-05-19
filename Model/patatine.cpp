#include "patatine.h"

Patatine::Patatine():Product("Patatine"){}
Patatine* Patatine::clone() const{//ovverride from Product
return new Patatine(*this);
}
