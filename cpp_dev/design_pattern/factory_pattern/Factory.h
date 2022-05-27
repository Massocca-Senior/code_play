#ifndef _FACTORY_H_
#define _FACTORY_H_
class Product;

class Factory
{
private:
    /* data */
public:
    Factory(/* args */);
    ~Factory();
    virtual Product* CreateProduct() = 0;
};

class  ConcreteFactory:public Factory
{
private:
    /* data */
public:
     ConcreteFactory(/* args */);
    ~ ConcreteFactory();
    Product* CreateProduct();

};

#endif