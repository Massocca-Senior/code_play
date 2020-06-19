#ifndef __MEMORY_TESTER_H
#define __MEMORY_TESTER_H
#include <iostream>
#include "Tester.h"

class MemoryTester :public Tester
{
private:
    /* data */
public:

    MemoryTester(/* args */);
    virtual int StartWork()
    {
        int  ret = 0;
        cout << "Startting do memory test" << endl;
        return ret;
    }
    ~MemoryTester();
};
#endif
