#pragma once


// CSaveDiary �Ի���

class CSaveDiary : public CDialogEx
{
	DECLARE_DYNAMIC(CSaveDiary)

public:
	CSaveDiary(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSaveDiary();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAVEDIARY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
