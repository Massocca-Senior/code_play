/*
 *  Description: Copyright XXXXX Inc.
 *  Create Time: 2020-06-04 15:53:58
 *  Modified by: Jack Ma
 *  Author: Jack Ma
 */
#ifndef __TESTER_H
#define __TESTER_H
#include <iostream>
using namespace std;
class Tester
{
private:
    /* data */
    string t_name;
    uint32_t t_cycle; 
    
public:
    Tester(/* args */);
    virtual int StartWork(){}
    ~Tester();
};

#endif