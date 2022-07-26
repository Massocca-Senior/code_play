#ifndef _BUILDER_H_
#define _BUILDER_H_
#include <string>
using namespace std;
class Product;

class Builder
{
private:
public:
    virtual void BuildPartA(const string& buildPara) = 0;
    virtual void BuildPartB(const string& buildPara) = 0;
    virtual void BuildPartC(const string& buildPara) = 0;
    virtual Product* GetProduct() = 0;
    Builder(/* args */);
    virtual ~Builder();
};

class ConcreteBuilder:public Builder
{
private:
    /* data */
public:
    ConcreteBuilder(/* args */);
    ~ConcreteBuilder();
    void BuildPartA(const string& buildPara);
    void BuildPartB(const string& buildPara);
    void BuildPartC(const string& buildPara);
    Product* GetProduct();
    
};


#endif