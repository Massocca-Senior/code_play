#include "Director.h"
#include "Builder.h"

Director::Director(Builder *bld)
{
    _bld = bld;
}

Director::~Director()
{
}

void Director::Construt()
{
    _bld->BuildPartA("Head");
    _bld->BuildPartB("Body");
    _bld->BuildPartC("Foot");
}