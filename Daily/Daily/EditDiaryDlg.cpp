// EditDiaryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Daily.h"
#include "EditDiaryDlg.h"
#include "afxdialogex.h"


// CEditDiaryDlg 对话框

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


// CEditDiaryDlg 消息处理程序


void CEditDiaryDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
