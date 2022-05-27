#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(/* args */)
{
}

Product::~Product()
{
}


ConcreteProduct::ConcreteProduct(/* args */)
{
    cout << "Create ConcreteProduct" << endl;
}

ConcreteProduct::~ConcreteProduct()
{
    cout << "Destroy ConcreteProduct" <<endl;
}

void ConcreteProduct::ShowProductName()
{
    cout << "This is ConcreteProduct" <<endl;
}

