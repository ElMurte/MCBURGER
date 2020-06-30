#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Model/restorant.h"
#include "View/clientwindow.h"
#include "View/uicuoco.h"
#include "View/uimanager.h"
class ClientWindow;
class ControllerR:public QObject{
    Q_OBJECT
public:
    explicit ControllerR(Restorant* r,QObject *parent = nullptr);
    void set_View(ClientWindow* v);
    void set_Cuoco(UICuoco* c);
    void set_Manager(UIManager *vm);
public slots:
    void FilterProductsonclick(const QString&);
    void FilterProductsonclick(const vector<QString>& qs);
    void Home();//da fare
    void resetOrdinazione();//da fare
   // void getPointerProduct(const QString&);
    void addthisprodtocart(Product*);
    void createneworder(vector<Product*>&);
    void orderready(Order*o);
private:
ClientWindow* view;
Restorant * model;
UICuoco* viewcuoco;
UIManager*viewmanager;
signals:
 void newData(const vector<Product*>& p);
 void newData(const QString& p);
 void productdata(Product*);
 void addProdtocart(Product*);
 void ordineaggiunto(Order*);
 void ordineprep(Order*);
};

#endif // CONTROLLER_H

