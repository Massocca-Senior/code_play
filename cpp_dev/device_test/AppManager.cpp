#include "AppManager.h"
#include<iostream>

AppManager::AppManager(/* args */)
{
    cout << "AppManager Inited" <<endl;
}

AppManager::~AppManager()
{
    cout << "AppManager Deinted" <<endl;
}

int AppManager::RegisterApp(Tester *app)
{
    cout << "register app " <<endl;
    app_list.push_back(app);
    return 0;
}

int AppManager::DeleteApps()
{
    for(list<Tester *>::iterator ai = app_list.begin(); ai != app_list.end(); ai++){
        delete (*ai);        
    } 
	return 0;   
}

int AppManager::InitApps()
{
    list<Tester *>::iterator ai ;
    for ( ai = app_list.begin(); ai != app_list.end(); ai++){
            (*ai)->StartWork();
    }
    return 0;
}
