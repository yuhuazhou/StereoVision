/********************************************************************
	��������:	2012/10/28
	�ļ�����: .\StereoVision\StereoVision\StereoMatch.h
	����:	StereoMatch
	����:	���
	
	����:	˫Ŀƥ������ά�ؽ���
*********************************************************************/
#ifndef _STEREO_MATCH_H_
#define _STEREO_MATCH_H_

#pragma once

#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/contrib/contrib.hpp"

using namespace std;

class StereoMatch
{
public:
	StereoMatch(void);
	virtual ~StereoMatch(void);

	int init(int imgWidth, int imgHeight, const char* xmlFilePath);

	int bmMatch(cv::Mat& frameLeft, cv::Mat& frameRight, cv::Mat& disparity, cv::Mat& imageLeft, cv::Mat& imageRight);

	int sgbmMatch(cv::Mat& frameLeft, cv::Mat& frameRight, cv::Mat& disparity, cv::Mat& imageLeft, cv::Mat& imageRight);

	int varMatch(cv::Mat& frameLeft, cv::Mat& frameRight, cv::Mat& disparity, cv::Mat& imageLeft, cv::Mat& imageRight);

	int getPointClouds(cv::Mat& disparity, cv::Mat& pointClouds);

	int getDisparityImage(cv::Mat& disparity, cv::Mat& disparityImage, bool isColor = true);

	void savePointClouds(cv::Mat& pointClouds, const char* filename);
    
    void setViewField(int viewWidth, int viewHeight, int viewDepth)
    {
        m_nViewWidth = viewWidth;
        m_nViewHeight = viewHeight;
        m_nViewDepth = viewDepth;
    }

    void getTopDownView(cv::Mat& pointClouds, cv::Mat& topDownView, cv::Mat& image = cv::Mat());
    
    void getSideView(cv::Mat& pointClouds, cv::Mat& sideView, cv::Mat& image = cv::Mat());

	/***
	 *	��������
	 */	
	cv::StereoBM		m_BM;				// ����ƥ�� BM ����
	cv::StereoSGBM		m_SGBM;				// ����ƥ�� SGBM ����
	cv::StereoVar		m_VAR;				// ����ƥ�� VAR ����
	double				m_FL;				// �������У����Ľ���ֵ

private:

	int loadCalibData(const char* xmlFilePath);

	/***
	 *	˽�б���
	 */
	bool	m_Calib_Data_Loaded;		// �Ƿ�ɹ����붨�����
	cv::Mat m_Calib_Mat_Q;				// Q ����
	cv::Mat m_Calib_Mat_Remap_X_L;		// ����ͼ����У����������ӳ����� X
	cv::Mat m_Calib_Mat_Remap_Y_L;		// ����ͼ����У����������ӳ����� Y
	cv::Mat m_Calib_Mat_Remap_X_R;		// ����ͼ����У����������ӳ����� X
	cv::Mat m_Calib_Mat_Remap_Y_R;		// ����ͼ����У����������ӳ����� Y
	cv::Mat m_Calib_Mat_Mask_Roi;		// ����ͼУ�������Ч����
	cv::Rect m_Calib_Roi_L;				// ����ͼУ�������Ч�������
	cv::Rect m_Calib_Roi_R;				// ����ͼУ�������Ч�������

	int m_frameWidth;					// ֡��
	int m_frameHeight;					// ֡��
	int m_numberOfDisparies;			// �Ӳ�仯��Χ

    int m_nViewWidth;                   // �ӳ����
    int m_nViewHeight;                  // �ӳ��߶�
    int m_nViewDepth;                   // �ӳ����

};

#endif