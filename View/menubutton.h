#ifndef MENUBUTTON_H
#define MENUBUTTON_H


#include <QPushButton>
class MenuButton : public QPushButton
{
    Q_OBJECT
public:
    MenuButton(const QString& cat,const QString& label="",const QString& icon="",QWidget*parent=nullptr);

signals:
void clickedCell(const QString&);

private:
    QString categorie;
private slots:
void handleclick();
};

#endif // MENUBUTTON_H
