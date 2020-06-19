#include "AppManager.h"
#include<iostream>

AppManager::AppManager(/* args */)
{
    cout << "AppManager Inited" <<endl;
}

AppManager::~AppManager()
{
    cout << "AppManager Denited" <<endl;
}

int AppManager::RegisterApp(Tester *app)
{
    cout << "register app " <<endl;
    app_list.push_back(app);
}

int AppManager::DeleteApps()
{
    for(list<Tester *>::iterator ai = app_list.begin(); ai != app_list.end(); ai++){
        delete (*ai);        
    }    
}

int AppManager::InitApps()
{
    list<Tester *>::iterator ai ;
    for ( ai = app_list.begin(); ai != app_list.end(); ai++){
            (*ai)->StartWork();
    }
}