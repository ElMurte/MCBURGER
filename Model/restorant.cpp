#include "restorant.h"
void Restorant::LoaddatafromJSON(){/*alloco la memoria per i prodotti e li legge dal file json*/
    Database::ReadProductfromJson<Product,Burger>("Burger",products);
    Database::ReadProductfromJson<Product,Patatine>("Patatine",products);
    Database::ReadProductfromJson<Product,Drink>("Drink",products);
    Database::ReadProductfromJson<Product,Sweet>("Sweet",products);
    /*MENU ??? */
    /*Employes*/
}

Restorant::Restorant(){
LoaddatafromJSON();

}
/*utility function*/
void Restorant::printproducts(){//test function
for(auto it=products.begin();it!=products.end();it++)
   cout<<(*it)->Get_Nome()<<endl<<(*it)->Get_Description()<<endl<<(*it)->Get_Calories()<<endl<<(*it)->Get_Price()<<endl<<endl;
}




