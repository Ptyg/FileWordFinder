#ifndef TIMER
#define TIMER

#include <iostream>
#include <chrono>
#include <string>
#include <memory>

class Timer{
    std::chrono::time_point<std::chrono::high_resolution_clock> _startTimepoint;
    std::string _timerPlaceName{};
public:
    Timer() : _startTimepoint(std::chrono::high_resolution_clock::now()) {}
    Timer(std::string&& name) : _startTimepoint(std::chrono::high_resolution_clock::now()), _timerPlaceName(std::move(name)) {}
    ~Timer() {
        auto _entTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(_startTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(_entTimepoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001; 
        if (_timerPlaceName.size() > 0)
            std::cout << "[TIMER]" << "[" << _timerPlaceName << "] " << duration << "us (" << ms << "ms)\n";
        else
            std::cout << "[TIMER] " << duration << "us (" << ms << "ms)\n";
    }
};

#endif // TIMER