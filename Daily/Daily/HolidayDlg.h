#pragma once
#include "afxcmn.h"


// CHolidayDlg 对话框

class CHolidayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHolidayDlg)

public:
	CHolidayDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHolidayDlg();

// 对话框数据
	enum { IDD = IDD_HOLIDAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl mylist;
};
