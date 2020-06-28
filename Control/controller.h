#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Model/restorant.h"
#include "View/clientwindow.h"
class ClientWindow;
class ControllerR:public QObject{
    Q_OBJECT
public:
    explicit ControllerR(Restorant* r,QObject *parent = nullptr);
    void set_View(ClientWindow* v);
    explicit ControllerR(const ControllerR& c);
public slots:
    void FilterProductsonclick(const QString&);
    void FilterProductsonclick(const vector<QString>& qs);
    void Home();//da fare
    void resetOrdinazione();//da fare
    void getPointerProduct(const QString&);
    void addthisprodtocart(Product*);
    void createneworder(vector<Product*>&);
private:
ClientWindow* view;
Restorant * model;

signals:
 void newData(const vector<Product*>& p);
 void newData(const QString& p);
 void productdata(Product*);
 void addProdtocart(Product*);
 void ordineaggiunto(unsigned int);
};

#endif // CONTROLLER_H

