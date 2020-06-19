#ifndef __APP_MANAGER_H
#define __APP_MANAGER_H

#include "MemoryTester.h"
#include <list>

class AppManager
{
private:
    list<Tester *> app_list;
    
public:
    AppManager(/* args */);
    int RegisterApp(Tester *app);
    int InitApps();
    int DeleteApps();
    ~AppManager();
};
#endif