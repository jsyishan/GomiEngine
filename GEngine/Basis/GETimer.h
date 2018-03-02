#ifndef GETIMER_H
#define GETIMER_H

namespace ge {
    class GETimer {
    public:
        // Constructor
        GETimer();

        // Reset the timer
        void reset();

        // Get the time since constructed
        // or get the time since lastly reset
        float getCurrentTime() const;

    private:

    #if defined(_WIN32) || defined(_WIN64)
        double win_timer_start;
        static double win_timer_frequency;
    #elif defined(__linux__) || defined(__APPLE__)
        unsigned long unix_timer_sec;
        unsigned long unix_timer_usec;
    #endif
    };
}

#endif