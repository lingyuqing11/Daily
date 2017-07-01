#pragma once
#include "afxdtctl.h"


// CEditDiaryDlg 对话框

class CEditDiaryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditDiaryDlg)

public:
	CEditDiaryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditDiaryDlg();

// 对话框数据
	enum { IDD = IDD_EDITDIARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	CDateTimeCtrl m_CtrlDate;
};
