#ifndef UIMANAGER_H
#define UIMANAGER_H
#include <View/clientwindow.h>
#include <View/uicuoco.h>
class UIManager : public ClientWindow
{
    Q_OBJECT
private:
    ClientWindow*cw;
UICuoco*cucina;
public:
    UIManager(ControllerR*c,QWidget*parent=nullptr);
public slots:
    void showUICucina();
    UICuoco *getcucina();
};

#endif // UIMANAGER_H
