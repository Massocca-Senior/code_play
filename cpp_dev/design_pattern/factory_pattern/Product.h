#ifndef _PRODUCT_H_
#define _PRODUCT_H_
class Product
{
private:
    /* data */
public:
    Product(/* args */);
    ~Product();
    virtual void ShowProductName() = 0;
};

class ConcreteProduct:public Product
{
private:
    /* data */
public:
    ConcreteProduct(/* args */);
    ~ConcreteProduct();
    void ShowProductName();
};

    
#endif