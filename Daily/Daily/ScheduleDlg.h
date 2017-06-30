#pragma once


// CScheduleDlg 对话框

class CScheduleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScheduleDlg)

public:
	CScheduleDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScheduleDlg();

// 对话框数据
	enum { IDD = IDD_SCHEDULE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
