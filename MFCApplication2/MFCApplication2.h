
// MFCApplication2.h : MFCApplication2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFCApplication2App:
// 有关此类的实现，请参阅 MFCApplication2.cpp
//

class CMFCApplication2App : public CWinAppEx
{
public:
	CMFCApplication2App();

	CArray<HWND, HWND> m_aryFrames;
public:

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	afx_msg void OnAppAbout();
	afx_msg void OnFileNewFrame();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2App theApp;
