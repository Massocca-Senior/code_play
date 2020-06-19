/**
 * @ Author: Your name
 * @ Create Time: 2020-05-28 10:02:25
 * @ Modified by: Your name
 * @ Modified time: 2020-06-03 14:47:44
 * @ Description:
 */

#include "common.h"
#include<iostream>

using namespace std;

static AppManager *apm = NULL;

void add_app(Tester *app){
    if(apm == NULL){
      apm = new AppManager();
    }
    apm->RegisterApp(app);
}

int main(int argc ,char *argv[])
{
    apm->InitApps();
    apm->DeleteApps();
    delete apm;
}