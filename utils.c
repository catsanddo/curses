#include "utils.h"
#include <time.h>

#ifndef _WIN32
    void Sleep(int millis) { usleep(millis * 1000.0); }
#endif

// Global time
clock_t now;

void tick(int fps)
{
    int elapsed = clock() - now;
    elapsed = (float) elapsed / CLOCKS_PER_SEC * 1000.0;
    int spf = 1.0 / fps * 1000.0;
    Sleep(spf - elapsed);
    now = clock();
}
