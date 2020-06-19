#include <iostream>
#include "Tester.h"
using namespace std;
class FlashTester : public Tester
{
private:
    /* data */
public:
    FlashTester(/* args */);
    virtual int StartWork(){
        cout << "Do Flash test" <<endl;
    }
    ~FlashTester();
};

