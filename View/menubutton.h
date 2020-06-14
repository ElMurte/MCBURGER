#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>
class MenuButton : public QPushButton
{
    Q_OBJECT
public:
    MenuButton(const QString& cat,int pag, const QString& label="", const QString& icon="", QWidget *parent=nullptr);

signals:
void clickedCell(const QString&);
void clickedCell(const int&);
private:
    QString categorie;
    int page;
private slots:
void handleclick();
void fakehandleclick();
};

#endif // MENUBUTTON_H
