#include "Builder.h"
#include "Product.h"
#include <iostream>

using namespace std;

Builder::Builder(/* args */)
{
}

Builder::~Builder()
{
}


ConcreteBuilder::ConcreteBuilder(/* args */)
{

}
ConcreteBuilder::~ConcreteBuilder()
{
}

void ConcreteBuilder::BuildPartA(const string& buildPara)
{
    cout <<"Step1:Build PartA..."<< buildPara <<endl;
}

void ConcreteBuilder::BuildPartB(const string& buildPara)
{
    cout <<"Step2:Build PartB..."<< buildPara <<endl;
}

void ConcreteBuilder::BuildPartC(const string& buildPara)
{
    cout <<"Step3:Build PartC..."<< buildPara <<endl;
}

Product* ConcreteBuilder::GetProduct()
{
    BuildPartA("Head");
    BuildPartB("Body");
    BuildPartC("Foot");
    return new Product();
}