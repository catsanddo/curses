#ifndef UTILS_H
#define UTILS_H

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void tick(int fps);

#endif
