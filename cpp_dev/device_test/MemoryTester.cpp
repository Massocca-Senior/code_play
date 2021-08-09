#include "MemoryTester.h"
#include "common.h"

MemoryTester::MemoryTester(/* args */)
{
    cout << "Memory tester inited" <<endl;
}

MemoryTester::~MemoryTester()
{
    cout << "Memory tester deinited" <<endl;
}

APP_INSTALL(201){
    MemoryTester *mt;
    mt = new MemoryTester();
    add_app(mt);
}