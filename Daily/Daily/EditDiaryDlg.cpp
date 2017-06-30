// EditDiaryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Daily.h"
#include "EditDiaryDlg.h"
#include "afxdialogex.h"


// CEditDiaryDlg �Ի���

IMPLEMENT_DYNAMIC(CEditDiaryDlg, CDialogEx)

CEditDiaryDlg::CEditDiaryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditDiaryDlg::IDD, pParent)
{

}

CEditDiaryDlg::~CEditDiaryDlg()
{
}

void CEditDiaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditDiaryDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CEditDiaryDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CEditDiaryDlg ��Ϣ�������


void CEditDiaryDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strText(_T(""));
	CString strFileName(_T(""));
	GetDlgItemText(IDC_EDIT2, strText);
	GetDlgItemText(IDC_EDIT1, strFileName);
	strFileName = strFileName + ".txt";
	try
	{
		CStdioFile file;
		file.Open(strFileName, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		file.WriteString(strText);
		file.Close();
	}
	catch (CFileException *e)
	{
		e->ReportError();
		e->Delete();
	}
	CDialog::EndDialog(IDD_EDITDIARY);
}
