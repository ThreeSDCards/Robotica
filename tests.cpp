#include <iostream>
#include "Model/Time.h"
#include "Model/MotorDriver.h"
#include "Model/ServoDriver.h"
#include "Model/Square.h"
#include "Model/Shape.h"
using namespace std;

/*  
Testable units:
    -Time
    -MotorDriver
    -Point
    -ServoDriver
    -Square
    -Shape
    -Task
*/

int main()
{
    cout << "Running class diagnostics:\n";
    cout << "\tTime        :" << (test_Time() ? "OK\n" : "ERR\n");
    cout << "\tMotorDriver :" << (test_MotorDriver() ? "OK\n" : "ERR\n");
    cout << "\tPoint       :" << (test_Point() ? "OK\n" : "ERR\n");
    cout << "\tServoDriver :" << (test_ServoDriver() ? "OK\n" : "\n");
    cout << "\tModule      :" << (test_Module() ? "OK\n" : "ERR\n");
    cout << "\tSquare      :" << (test_Square() ? "OK\n" : "ERR\n");
    cout << "\tShape       :" << (test_Shape() ? "OK\n" : "ERR\n");
    return 0;
}