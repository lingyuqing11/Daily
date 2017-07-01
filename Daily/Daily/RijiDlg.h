#pragma once
#include "afxcmn.h"
#include "afxdtctl.h"


// CRijiDlg 对话框

class CRijiDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRijiDlg)

public:
	CRijiDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRijiDlg();

// 对话框数据
	enum { IDD = IDD_DIARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();
	HICON m_hIcon;


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	CListCtrl mylist;
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	CDateTimeCtrl m_DateCtrl;
	CString DataDeleteZero(CString DATA);
	afx_msg void OnBnClickedButton1();
};
