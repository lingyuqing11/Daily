#pragma once


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

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
};
