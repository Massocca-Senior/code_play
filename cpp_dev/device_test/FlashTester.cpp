#include "FlashTester.h"
#include "common.h"

FlashTester::FlashTester(/* args */)
{
    cout << "Init Flashtester" << endl;
}

int FlashTester::StartWork()
{
    cout << "Starting do Flash test" << endl;
}

FlashTester::~FlashTester()
{
    cout << "Deinit Flashtester" << endl;
}

APP_INSTALL(200){
    FlashTester *ft = new FlashTester();
    add_app(ft);
}