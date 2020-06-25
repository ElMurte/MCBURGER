#ifndef ADDREMBUTTONSCART_H
#define ADDREMBUTTONSCART_H

#include <QWidget>
#include <QPushButton>
#include <View/cart.h>
class Product;
class Cart;
class AddRemButtonsCart : public QWidget{
private:
    Cart* carel;
    Product*p;
    unsigned int riga;
    QPushButton*addpbtn;
    QPushButton*rempbtn;
    Q_OBJECT
public:
    explicit AddRemButtonsCart(Cart*c,Product*p,unsigned int row,QWidget *parent = nullptr);
public slots:
    void remquantita_tocart();
    void add_quantita_tocart();
signals:
void quantitachange(unsigned int);
};

#endif // ADDREMBUTTONSCART_H
