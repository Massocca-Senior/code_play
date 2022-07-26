#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Product
{
private:
    /* data */
public:
    Product(/* args */);
    ~Product();
    void ProducePart();
};

class ProductPart
{
private:
    /* data */
public:
    ProductPart(/* args */);
    ~ProductPart();
    ProductPart* BuildPart();
};

#endif