#pragma once


// CScheduleDlg �Ի���

class CScheduleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScheduleDlg)

public:
	CScheduleDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CScheduleDlg();

// �Ի�������
	enum { IDD = IDD_SCHEDULE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
