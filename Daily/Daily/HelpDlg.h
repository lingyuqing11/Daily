#pragma once
#include "afxwin.h"


// CHelpDlg �Ի���

class CHelpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHelpDlg)

public:
	CHelpDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHelpDlg();

// �Ի�������
	enum { IDD = IDD_HELP };

protected:
	virtual BOOL OnInitDialog();
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	CStatic picture;
};
