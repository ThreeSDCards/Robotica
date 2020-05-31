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
#include <sstream>
#include <opencv2/core/utility.hpp> //libs voor opencv
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;
void simulationLoop();
void render();
int camera();

Model* model;
View* view;

int main(int ac, char **ap)
{
	glutInit(&ac, ap);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("v0.0.2");
	model = new Model();
	model->Init();
	view = new View(model);
	camera(); //call camera function
	std::cout << "Initialization succesful.\n";
	glutIdleFunc(simulationLoop);
	glutDisplayFunc(render);
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
	glFlush();
}

int camera()
{
	//cv::namedWindow("raw", cv::WINDOW_AUTOSIZE); //window for color
	cv::namedWindow("gray", cv::WINDOW_AUTOSIZE); //window for gray
	//cv::namedWindow("canny", cv::WINDOW_AUTOSIZE); \\window for canny

	cv::VideoCapture cap; //opent je camera
	cap.open(0);

	if (!cap.isOpened()) 
	{
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}

	cv::Mat bgr_frame, gray, canny; //maak frames

	for (int i =0; i<50; i++) //50 x 100 ms de tijd om cirkel voor camera te houden
	{
		cap >> bgr_frame; //capture wordt frame
		if (bgr_frame.empty()) break;

		//cv::imshow("raw", bgr_frame); //laat color zien

		cv::cvtColor(bgr_frame, gray, cv::COLOR_BGR2GRAY); //convert color to gray
		/*if (i == 49) { //is for image scannen werkt nog niet helemaal lekker
			for (int i = 0; i < gray.rows; i++)
				for (int j = 0; j < gray.cols; j++)
					std::cout << gray.at<uchar>(i, j) << std::endl;
		}*/
		cv::imshow("gray", gray); //laat gray zien
		
		//cv::Canny(gray, canny, 10, 100, 3, true); //convert gray to canny
		//cv::imshow("canny", canny); //laat canny zien

		char c = cv::waitKey(10);
		if (c == 27) break;
		Sleep(100);
	}

	cap.release(); //camera uit
	return 0;
}
