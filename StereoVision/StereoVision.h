
// StereoVision.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CStereoVisionApp:
// �йش����ʵ�֣������ StereoVision.cpp
//

class CStereoVisionApp : public CWinApp
{
public:
	CStereoVisionApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CStereoVisionApp theApp;