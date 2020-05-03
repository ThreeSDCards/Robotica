#include "Time.h"

void Time::Update()
{
    auto now = std::chrono::high_resolution_clock::now();

    //Calculate ms elapsed
    auto elapsed = now - lastTime;
    DeltaTime = elapsed.count();

    //Update last known time
    lastTime = now;
}

bool test_Time()
{
    try
    {
        using namespace std::chrono_literals;
        Time t;
        std::this_thread::sleep_for(1s);
        t.Update();
        if (t.DeltaTime > 1005 || t.DeltaTime < 995)
            throw "TIME ERROR";
    }
    catch (const char *e)
    {
        return false;
    }
    return true;
}