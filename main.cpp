#include <GL/glut.h>
#include <iostream>
#include <map>
#include "Model/Time.h"
#include "Model/ServoDriver.h"
#include "Model/Module.h"

Time *_time;
std::map<const std::string &, Module> *_modules;

void simulationLoop();
void render();

int main(int ac, char **ap)
{
    glutInit(&ac, ap);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Test");
    //Initialize global variables
    _time = new Time();
    _modules = new std::map<const std::string &, Module>();

    glutDisplayFunc(render);
    glutIdleFunc(simulationLoop);
    glutMainLoop();
    return 0;
}

void simulationLoop()
{
    //TODO - implement simulation loop
    auto &time = *_time;
    auto &modules = *_modules;

    //Update global time variable
    time.Update();

    //Execute routines
    // modules["XDriver"].Routine(time.DeltaTime);
}

void render()
{
    glClearColor(0, 0, 1.0, 0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.7, 0.7, 0);
    glVertex3f(0.7, 0.7, 0);
    glVertex3f(0, -1, 0);
    glEnd();
    glFlush();
}