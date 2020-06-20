#ifndef CART_H
#define CART_H
#include <QLabel>
#include <QDialog>
class Cart : public QDialog{
    Q_OBJECT
private:

public slots:

signals:

public:
    Cart(QWidget* parent = nullptr);
    void ShowCartWindow();
};

#endif // CART_H
