#include "Singleton.h"
#include <iostream>

using namespace std;

Singleton *Singleton::_instance = 0;

Singleton::Singleton(/* args */)
{
    cout <<" Singleton..." << endl;
}

Singleton::~Singleton()
{
}

Singleton *Singleton::Instance()
{
    if (_instance == 0) {
            _instance = new Singleton();
    }

    return _instance;
}

void Singleton::ShowVersion()
{
    cout << "V0.0.1"<<endl;
}
