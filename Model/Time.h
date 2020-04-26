#pragma once
#include <chrono>

class Time
{
    std::chrono::_V2::system_clock::time_point lastTime;

public:
    Time() : lastTime(chrono::high_resolution_clock::now()){};
    float DeltaTime;
    void Update();
};