#include "Timer.h"


// Timer::Timer()
// {}
Timer::Timer(const std::function<void(void)>& f): funct(f)
{}
Timer::Timer(const std::function<void(void)>& f,const unsigned long& i,const long repeat = Timer::infinite):funct(f),
                                                                                                            interval(std::chrono::milliseconds(i)),
                                                                                                            CallNumber(repeat)
{}


Timer::Timer():Alive(false),CallNumber(-1L),repeat_count(-1L)
                ,interval(std::chrono::milliseconds(0))
                ,funct(nullptr)
{}

void Timer::Start(bool Async = true)
{
    if(isAlive())
        return;
    Alive = true;
    repeat_count = CallNumber;
    if(Async)
        Thread = std::thread(&Timer::ThreadFunc,this);
    else
    {
        this->ThreadFunc();
    }
    
}
void Timer::Stop()
{
    Alive = false;
    Thread.join();
}

void Timer::SetFunction(const std::function<void(void)>& f)
{
    funct = f;
}

bool Timer::isAlive() const
{
    return Alive;
}
void Timer::RepeatCount(const long r)
{
    if(Alive)
        return;
    CallNumber = r;
}
long Timer::GetLeftCount() const 
{
    return repeat_count;
}
long Timer::RepeatCount() const
{
    return CallNumber;
}
void Timer::SetInterval(const unsigned long &i)
{
    if(Alive)
        return;

    interval = std::chrono::milliseconds(i);
}
unsigned long Timer::Interval() const
{
    return static_cast<unsigned long>(interval.count());
}
const std::function<void(void)> &Timer::Function() const
{
    return funct;
}

//////////////////////////////////////////////////////
///////////     private members     //////////////////
//////////////////////////////////////////////////////
void Timer::SleepAndRun()
{
    std::this_thread::sleep_for(interval);
    if(Alive)
    {
        Function()();
    }
}
void Timer::ThreadFunc()
{
    if(CallNumber == infinite)
    {
        while(Alive)
            SleepAndRun();
    }
    else
    {
        while(repeat_count--)
            SleepAndRun();
    }
    
}



const long Timer::infinite = -1L;