#pragma once


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
};
