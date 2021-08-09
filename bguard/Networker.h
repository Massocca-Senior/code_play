#ifndef __NETWORKER_H_
#define __NETWORKER_H_
#include<linux/socket.h>
class Networker{
    
    private:
    int net_fd;
    string server_ip;
    short int port;

    public:
    Networker(string server_ip, short int port);
    int NetStart();


};

#endif