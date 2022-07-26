#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
class Builder;

class Director
{
private:
    /* data */
    Builder *_bld;
public:
    Director(Builder *bld);
    ~Director();
    void Construt();
};


#endif