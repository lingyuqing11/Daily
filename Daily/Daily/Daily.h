
// Daily.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDailyApp:
// �йش����ʵ�֣������ Daily.cpp
//

class CDailyApp : public CWinApp
{
public:
	CDailyApp();
public:
	CString str = "";
	CStringA strFile;
// ��д
public:
	virtual BOOL InitInstance();
	_ConnectionPtr m_pConnection;
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDailyApp theApp;