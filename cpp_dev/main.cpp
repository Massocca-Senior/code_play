#include<iostream>

using namespace std;

class AutoProxy
{
private:
    /* data */
public:
    AutoProxy(/* args */);
    ~AutoProxy();
};

AutoProxy::AutoProxy(/* args */)
{
    cout << "Init the AutoProxy..." <<endl;
}

AutoProxy::~AutoProxy()
{
    cout << "Uninit the the AutoProxy... " <<endl;
}

int main(int argc ,char *argv[])
{
    AutoProxy ap;
    cout << "Startting AutoProxying..." <<endl;

}