#pragma once
#include "afxdtctl.h"


// CEditDiaryDlg �Ի���

class CEditDiaryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditDiaryDlg)

public:
	CEditDiaryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditDiaryDlg();

// �Ի�������
	enum { IDD = IDD_EDITDIARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	CDateTimeCtrl m_CtrlDate;
};
