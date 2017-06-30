#pragma once


// CMusicDlg 对话框

class CMusicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMusicDlg)

public:
	CMusicDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMusicDlg();

// 对话框数据
	enum { IDD = IDD_MUSIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
