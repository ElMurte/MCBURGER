#ifndef WINDOWADDPRODUCT_H
#define WINDOWADDPRODUCT_H
#include <QCloseEvent>
#include <QDialog>


class ControllerR;
class Product;
class QLabel;
class QTextBrowser;
class WindowAddProduct : public QDialog{
    Q_OBJECT
private:
Product* p;

QPixmap img;//get immagine
QLabel* picture;
QLabel* name;
QTextBrowser* desc;
QLabel* price;
QWidget*psa;
protected:
public:
    WindowAddProduct(QWidget* parent = nullptr);
    bool isthesame(Product *ptr)const;
    void showWindow(const QString& nome,const QString& imma,const QString& descriz,const double& prezzo);
public slots:

signals:
};

#endif // WINDOWADDPRODUCT_H
