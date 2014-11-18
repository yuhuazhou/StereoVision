/********************************************************************
	���� :	2012/10/28
	�ļ� :	.\StereoVision\StereoVision\PointCloudAnalyzer.h
	���� :	PointCloudAnalyzer
	���� :	��� chenyusiyuan AT 126 DOT com
	
	���� :	���Ʒ����������������ͷ�ļ�
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

	// ������Ϣ �ṹ��
	struct ObjectInfo
	{
		cv::Point		center;		//����
        cv::Point       nearest;    //�����
		double			distance;	//����
		double			area;		//���
		cv::Rect		boundRect;	//��Ӿ���
		cv::RotatedRect minRect;	//��С����

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