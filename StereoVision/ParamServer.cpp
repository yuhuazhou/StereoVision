#include "StdAfx.h"
#include "ParamServer.h"


ParamServer* ParamServer::_instance = NULL;


ParamServer::ParamServer() 
{
	init();
}

ParamServer* ParamServer::instance() {
	if (_instance == NULL) {
		_instance = new ParamServer();
	}
	return _instance;
}


void ParamServer::init()
{
	bool isOpened = fs.open("D:\\Projects\\Kinect_NI\\Release\\params.yml", cv::FileStorage::READ);
	if (!isOpened)
	{
		isOpened = fs.open("params.yml", cv::FileStorage::READ);
	}

	if ( isOpened )
	{
		printf("[- Paramater Loading] Loaded data from File params.yml .");

		fs["image_width"]		>> image_width;
		fs["image_height"]		>> image_height;
	} 
	else
	{
		printf("[- Paramater Loading] File params.yml does not exist, load default values.");

		image_width		= 640;
		image_height	= 480;
	}
}


