#pragma once


// CRijiDlg �Ի���

class CRijiDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRijiDlg)

public:
	CRijiDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRijiDlg();

// �Ի�������
	enum { IDD = IDD_DIARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
};