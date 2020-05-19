#include "restorant.h"
Restorant::Restorant(){
    Database::ReadfromJson<Product,Burger>("Panino",products);/*alloco memoria da o con DB e leggo read() dentro Restourant()*/
    Database::ReadfromJson<Product,Patatine>("Patatine",products);

}
/*utility function*/
void Restorant::printproducts(){//test function
for(auto it=products.begin();it!=products.end();it++)
   cout<<(*it)->Get_Nome()<<endl<<(*it)->Get_Description()<<endl<<(*it)->Get_Calories()<<endl<<(*it)->Get_Price()<<endl<<endl;
}




