#include<iostream>
#include<linux/socket.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include "Networker.h"

using namespace std;

Networker::Networker(string server_ip, short int port)
{
    this->server_ip = server_ip;
    this->port = port;
    cout << "server_ip is :" << this->server_ip << "port is :" << this->port << endl;
    
}

int Networker::NetStart()
{
    struct sockaddr_in serv_addr, cli_addr;
    struct ip_mreqn group;
    int ret = -1;

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(this->port);

    this->net_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(this->net_fd < 0 ){
        cout << "\nbind socket failed" << strerror(errno) << endl;
        return ret;
    }

    ret = bind(this->net_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if(ret < 0 ){
        cout << "\nbind socket failed" << strerror(errno) << endl;
        return ret;
    }

    group.imr_multiaddr.s_addr = inet_addr(server_ip.c_str());
    group.imr_address.s_addr = htonl(INADDR_ANY);

    ret = setsockopt(this->net_fd, IPPROTO_IP, IP_MULTICAST_IF, &group, sizeof(group));
    if(ret < 0){
        cout << "\nsetsockopt failed" << strerror(errno) << endl;
        return ret;
    }

}