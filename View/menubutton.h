#ifndef MENUBUTTON_H
#define MENUBUTTON_H


#include <QPushButton>
class MenuButton : public QPushButton
{
    Q_OBJECT
public:
    MenuButton(QString cat,QString label="",QString icon="",QWidget*parent=nullptr);

signals:
void clickedCell(QString);

private:
    QString icona;
    QString categorie;
private slots:
void cellEmitter();
};

#endif // MENUBUTTON_H
