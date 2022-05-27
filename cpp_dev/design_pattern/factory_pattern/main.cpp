#include "Factory.h"
#include "Product.h"

int main(int argc, char *argv[])
{
    Factory *fac = new ConcreteFactory();
    Product *p  = fac->CreateProduct();
    p->ShowProductName();

    return 0;
}