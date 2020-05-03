#pragma once
#include <chrono>
#include <thread>

class Time
{
    std::chrono::_V2::system_clock::time_point lastTime;

public:
    Time() : lastTime(std::chrono::high_resolution_clock::now()){};
    float DeltaTime;
    void Update();
};

bool test_Time();