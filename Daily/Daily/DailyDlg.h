
// DailyDlg.h : 头文件
//

#pragma once


// CDailyDlg 对话框
class CDailyDlg : public CDialogEx
{
// 构造
public:
	CDailyDlg(CWnd* pParent = NULL);	// 标准构造函数

	CListCtrl mylist;
	//_ConnectionPtr m_pConnection;
	//_RecordsetPtr m_pRecordset;
	//CDailyDlg(CWnd* pParent = NULL);	// 标准构造函数
	CBrush m_bkBrush;
	void toolbar_zzh();
	void AddToGrid();
	//CDailyDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_ImageList;						//图像列表
	CToolBar   m_ToolBar;						//工具栏对象
	CStatusBar m_StatusBar;						//状态栏对象

// 对话框数据
	enum { IDD = IDD_DAILY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton7();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnMcnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void On32775();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedIcon8();
	afx_msg void OnBnClickedIcon3();
	afx_msg void OnBnClickedIcon6();
	afx_msg void OnBnClickedIcon4();
};
