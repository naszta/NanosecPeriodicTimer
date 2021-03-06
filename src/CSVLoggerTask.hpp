/**
 * \class CSVLoggerTask
 *
 *
 * \brief Task that stores trigger times and writes them to a CSV file
 *
 * This class memorizes all expected and real trigger times
 * and writes to a CSV file upon destruction.
 *
 *
 * \author Ferenc Bodon
 *
 */

#pragma once

#include <string>
#include <vector>
#include "Task.hpp"


class CSVLoggerTask: public Task {
    private:  
        string filename;
    protected:
        vector<TIME> expectedTriggerTimes;
        vector<TIME> realTriggerTimes;

    public: 
        CSVLoggerTask(unsigned long, const char* argv[]);
        bool run(const TIME&, const TIME&);
        ~CSVLoggerTask();
};

