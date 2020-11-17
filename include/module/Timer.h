#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>
#include <functional>
        

class Timer
{
    std::thread Thread;
    bool Alive ;
    long CallNumber;
    long repeat_count = -1L;
    std::chrono::milliseconds interval ; 
    std::function<void(void)> funct;
    void SleepAndRun();
    void ThreadFunc();
public:
    Timer();
    Timer(const std::function<void(void)>&);
    Timer(const std::function<void(void)>&,const unsigned long&,const long);
    void Start(bool);
    void Stop();
    void SetFunction(const std::function<void(void)>&);
    bool isAlive() const;
    void RepeatCount(const long);
    long GetLeftCount() const;
    long RepeatCount() const;
    void SetInterval(const unsigned long&);
    unsigned long Interval() const;
    const std::function<void(void)>& Function() const;


    static const long infinite;

};



#endif