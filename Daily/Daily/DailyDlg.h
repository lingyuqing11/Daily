
// DailyDlg.h : ͷ�ļ�
//

#pragma once


// CDailyDlg �Ի���
class CDailyDlg : public CDialogEx
{
// ����
public:
	CDailyDlg(CWnd* pParent = NULL);	// ��׼���캯��

	CListCtrl mylist;
	//_ConnectionPtr m_pConnection;
	//_RecordsetPtr m_pRecordset;
	//CDailyDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CBrush m_bkBrush;
	void toolbar_zzh();
	void AddToGrid();
	//CDailyDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_ImageList;						//ͼ���б�
	CToolBar   m_ToolBar;						//����������
	CStatusBar m_StatusBar;						//״̬������

// �Ի�������
	enum { IDD = IDD_DAILY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
