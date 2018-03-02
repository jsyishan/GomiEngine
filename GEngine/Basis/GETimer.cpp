#include "GETimer.h"

#define NULL 0

namespace ge {
#if defined(_WIN32) || defined(_WIN64)

    double GETimer::win_timer_frequency = 0.0f;

    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #endif

    #include <windows.h>

    GETimer::GETimer() {
        LARGE_INTEGER large_int;

        QueryPerformanceFrequency(&large_int);
        win_timer_frequency = double(large_int.QuadPart);
        if (win_timer_frequency > 0.0f) 
            win_timer_frequency = 1000.0f / win_timer_frequency;
        
        QueryPerformanceCounter(&large_int);
        win_timer_start = double(large_int.QuadPart);
    }

    void GETimer::reset() {
        LARGE_INTEGER large_int;
        QueryPerformanceCounter(&large_int);
        win_timer_start = double(large_int.QuadPart);
    }

    double GETimer::getCurrentTime() const{
        LARGE_INTEGER large_int;
        QueryPerformanceCounter(&large_int);
        double counter = double(large_int.QuadPart);
        float time = float(win_timer_frequency * (counter - win_timer_start));
        return time;
    }

#elif defined(__linux__) || defined(__APPLE__)

    #include <sys/time.h>

    GETimer::GETimer() {
        reset();
    }

    void GETimer::reset() {
        timeval tv;
        gettimeofday(&tv, NULL);
        unix_timer_sec = tv.tv_sec;
        unix_timer_usec = tv.tv_usec;

    }

    float GETimer::getCurrentTime() const {
        timeval tv;
        gettimeofday(&tv, NULL);
        return 1000.0f * (tv.tv_sec - unix_timer_sec) + 0.001f * (tv.tv_usec - unix_timer_usec);
    }

#else

    GETimer::GETimer() {}

    void GETimer::reset() {}

    float GETimer::getCurrentTime() const { return 0.0f; }

#endif
}
