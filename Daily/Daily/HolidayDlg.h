#pragma once
#include "afxcmn.h"


// CHolidayDlg �Ի���

class CHolidayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHolidayDlg)

public:
	CHolidayDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHolidayDlg();

// �Ի�������
	enum { IDD = IDD_HOLIDAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl mylist;
};
