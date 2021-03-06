#pragma once

#include <chrono>

template<class T>
class PeriodicTimer {
    protected:    
        T& task;    
    public: 
        PeriodicTimer(T& t) : task{t} {}

        virtual void run(chrono::nanoseconds wait, unsigned long nr) = 0; 
        virtual ~PeriodicTimer() = default;
};


