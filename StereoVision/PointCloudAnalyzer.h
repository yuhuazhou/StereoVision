/********************************************************************
	创建 :	2012/10/28
	文件 :	.\StereoVision\StereoVision\PointCloudAnalyzer.h
	类名 :	PointCloudAnalyzer
	作者 :	邹宇华 chenyusiyuan AT 126 DOT com
	
	功能 :	点云分析与最近物体检测类头文件
*********************************************************************/

#ifndef _POINT_CLOUD_ANALYZER_H_
#define _POINT_CLOUD_ANALYZER_H_

#pragma once

#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/imgproc/imgproc_c.h>
#include "opencv2/highgui/highgui.hpp"

using namespace std;


class PointCloudAnalyzer
{
public:
	PointCloudAnalyzer(void);
	~PointCloudAnalyzer(void);

	// 物体信息 结构体
	struct ObjectInfo
	{
		cv::Point		center;		//中心
        cv::Point       nearest;    //最近点
		double			distance;	//距离
		double			area;		//面积
		cv::Rect		boundRect;	//外接矩形
		cv::RotatedRect minRect;	//最小矩形

		void operator = (const ObjectInfo& rhs) 
		{
            center = rhs.center;
            nearest = rhs.nearest;
			distance = rhs.distance;
			area = rhs.area;
			boundRect = rhs.boundRect;
			minRect = rhs.minRect;
		}

		bool operator < (const ObjectInfo& rhs ) const  
		{   
			return distance < rhs.distance; 
		}
		bool operator > (const ObjectInfo& rhs ) const  
		{   
			return distance > rhs.distance; 
		}

	};

	
	void detectNearObject(cv::Mat& image, cv::Mat& pointCloud, vector<ObjectInfo>& objectInfos);

private:

	
	void imageDenoising( cv::Mat& img, int iters );

	
	void parseCandidates(cv::Mat& objects, cv::Mat& depthMap, vector<ObjectInfo>& objectInfos);

	void showObjectInfo(vector<ObjectInfo>& objectInfos, cv::Mat& outImage);

};

#endif