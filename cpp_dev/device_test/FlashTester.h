#include <iostream>
#include "Tester.h"
using namespace std;
class FlashTester : public Tester
{
private:
    /* data */
public:
    FlashTester(/* args */);
    virtual int StartWork();
    ~FlashTester();
};

