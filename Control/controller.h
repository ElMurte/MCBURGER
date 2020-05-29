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
public slots:
    void FilterProductsonclick(const QString&);
    void Home();
    void resetOrdinazione();
private:
ClientWindow* view;
Restorant * model;
};

#endif // CONTROLLER_H

