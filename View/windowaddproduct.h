#ifndef WINDOWADDPRODUCT_H
#define WINDOWADDPRODUCT_H
#include <QCloseEvent>
#include <QWidget>


class ControllerR;
class Product;
class QLabel;
class QTextBrowser;
class WindowAddProduct : public QWidget{
    Q_OBJECT
private:
Product* p;

QPixmap img;//get immagine
QLabel* picture;
QLabel* name;
QTextBrowser* desc;
QLabel* price;
protected:
public:
    WindowAddProduct(Product* ptr, QWidget* parent = nullptr);
    WindowAddProduct(const QString& nome,const QString& imma,const QString& descriz,const double& prezzo,ControllerR*,QWidget *parent = nullptr);
    bool isthesame(const QString& nome,const QString& imma,const QString& descriz,const double& prezzo)const;
    void setProduct(Product*ptr);
public slots:

signals:
};

#endif // WINDOWADDPRODUCT_H
