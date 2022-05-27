#include "Factory.h"
#include "Product.h"
#include <iostream>

using namespace std;

Factory::Factory(/* args */)
{
}

Factory::~Factory()
{
}

ConcreteFactory:: ConcreteFactory(/* args */)
{
    cout << "Create ConcreteFactory" << endl;
}

ConcreteFactory::~ ConcreteFactory()
{
    cout << "Destroy ConcreteFactory" << endl;
}

Product* ConcreteFactory::CreateProduct()
{
    return new ConcreteProduct();
}