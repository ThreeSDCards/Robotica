#ifdef _WIN32
#include "../GL/glew.h"
#include "../GL/glut.h"
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "Model/Model.h"
#include "View/View.h"

#include <iostream>
void simulationLoop();
void render();

Model *model;
View *view;

int main(int ac, char **ap)
{
    glutInit(&ac, ap);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("v0.0.1");
    //Initialize global variables
    model = new Model();
    model->Init();

    //Initialize view
    view = new View(model);
    std::cout << "Initialization succesful.\n";
    glutDisplayFunc(render);
    glutIdleFunc(simulationLoop);
    glutMainLoop();
    return 0;
}

void simulationLoop()
{
    view->Update();
    render();
}

void render()
{
    glClearColor(0, 0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    view->Draw();
    glEnd();
    glFlush();
}
