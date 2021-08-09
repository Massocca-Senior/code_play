#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;

class MemoryFK
{
private:
    /* data */
public:
    MemoryFK(/* args */);
    void CreateFK(unsigned int num);
    ~MemoryFK();
};

MemoryFK::MemoryFK(/* args */)
{
    cout << "Init memory f**ker" <<endl;
}

MemoryFK::~MemoryFK()
{
    cout << "Init memory f**ker" <<endl;
}

void *do_mem_fk(void *data)
{
    cout << "Starting memory fucker number:" << *(int *)data << endl;
    while(1){
        int *p = new int[1024];
        if(!p){
            cout << "New int[10] failed" << endl;
            break;
        }
        p[1] = 10;
        p[0] = 2;
        delete []p;
        p = NULL;
    }
}


void MemoryFK::CreateFK(unsigned int num)
{
    int i = 0;
    int ret = 0;
    pthread_t pt[num];

    for(i = 0; i < num; i++){
         ret = pthread_create(&pt[i], NULL, do_mem_fk, (void *)&i);
        sleep(1);
    }

    sleep(1);

    for(i = 0; i < num ; i++){
        pthread_join(pt[i], NULL);
    }
}

int main(int argc, char *argv[])
{
    cout << "Startting to fucking the memory"<<endl;

    MemoryFK mf;

    mf.CreateFK(atoi(argv[1]));

    return 0;
}