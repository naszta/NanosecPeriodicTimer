#include <string>
#include <iostream>
#include <stdlib.h> 
#include <chrono>

#include "constant.hpp"
#include "KDBTradePublisher.hpp"
#include "PeriodicTimerByTimeCheck.hpp"

using namespace std;

int main(int argc, const char* argv[])
{
    if (argc < 5) {
        cerr << "Usage: " << argv[0] << "[freq] [dur] [host] [port]" << endl;
        return 1;
    }

    const unsigned long FREQ = atol(argv[1]);          // frequency
    chrono::nanoseconds WAIT(BILLION / FREQ);          // wait time between ticks
    cout << "Wait time is set to\t\t" << WAIT.count() << " nanosec" << endl;
    const unsigned int DUR = atoi(argv[2]);            // duration is second

    const unsigned long MAXRUN = DUR * FREQ;

    KDBTradePublisher task(MAXRUN, argv + 3);

    PeriodicTimerByTimeCheckJumpForward<KDBTradePublisher> timer(task); 
    timer.run(WAIT, MAXRUN);    

    return 0;
}