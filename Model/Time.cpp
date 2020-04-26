#include "Time.h"

void Time::Update()
{
    auto now = std::chrono::high_resolution_clock::now();

    //Calculate ms elapsed
    auto elapsed = now - lastTime;
    DeltaTime = elapsed.count;

    //Update last known time
    lastTime = now;
}