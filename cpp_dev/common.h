#ifndef __COMMON_H
#define __COMMON_H
#include "MemoryTester.h"
#include "AppManager.h"
void add_app(Tester *app);
#define APP_INSTALL(pro)                                                    \
    __attribute__((constructor)) static void install_app_##pro()
#endif