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
    vector<cv::String> fn;
	cv::glob("/ThisPC/Pictures/cirkels/*.png", fn, false);

	vector<cv::Mat> images=vector<cv::Mat>();
	size_t count = fn.size(); //number of png files in images folder
	for (size_t i = 0; i < count; i++)
		images.push_back(cv::imread(fn[i]));


	//cv::String path("/ThisPC/Pictures/cirkels/*.png"); //select only png out of folder cirkels
	//vector<cv::String> fn;
	//vector<cv::Mat> data;
	//cv::glob(path, fn, true); // recurse
	//for (size_t k = 0; k < fn.size(); ++k)
	//{
	//	cv::Mat im = cv::imread(fn[k]);
	//	if (im.empty()) continue; //only proceed if sucsessful
	//	// you probably want to do some preprocessing
	//	data.push_back(im);
	//}
    glutInit(&ac, ap);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("v0.0.2");
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
