#ifndef UIMANAGER_H
#define UIMANAGER_H
#include <View/clientwindow.h>
#include <View/uicuoco.h>
class Manager;
class UIManager : public ClientWindow
{
    Q_OBJECT
private:
    ClientWindow*cw;
    class Manager*manager;
UICuoco*cucina;

public:
    UIManager(ControllerR*c,class Manager*man,QWidget*parent=nullptr);
public slots:
    void showUICucina();
    UICuoco *getcucina();
};

#endif // UIMANAGER_H
