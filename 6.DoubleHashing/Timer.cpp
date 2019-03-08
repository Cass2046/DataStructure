/*
/ @file: Timer.cpp
/ @author: Lu Yin
/ @date: March 10, 018
*/

#include "Executive.h"

#include <sys/time.h>
class Timer
{
    private:
    timeval startTime;
    timeval endTime;

    public: 
    void start()
    {
        gettimeofday(&startTime, NULL);
    }

    double stop()
    {
        long seconds, nseconds;
        double duration;
        gettimeofday(&endTime, NULL);
        seconds = endTime.tv_sec - startTime.tv_sec;
        nseconds = endTime.tv_usec - startTime.tv_usec;
        duration = seconds + nseconds/1000000.0;
        return duration;
    }

    void PrintTime(double duration)
    {
        printf("%5.6f seconds\n", duration);
    }

};