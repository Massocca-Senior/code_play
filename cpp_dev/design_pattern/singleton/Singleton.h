#ifndef _SINGLETON_H_
#define _SINGLETON_H_
class Singleton
{
private:
    /* data */
    static Singleton *_instance;
public:
    ~Singleton();
    static Singleton* Instance();
    void ShowVersion();
protected:
    Singleton(/* args */);

};

#endif