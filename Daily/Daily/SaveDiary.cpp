// SaveDiary.cpp : 实现文件
//

#include "stdafx.h"
#include "Daily.h"
#include "SaveDiary.h"
#include "afxdialogex.h"


// CSaveDiary 对话框

IMPLEMENT_DYNAMIC(CSaveDiary, CDialogEx)

CSaveDiary::CSaveDiary(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SAVEDIARY, pParent)
{

}

CSaveDiary::~CSaveDiary()
{
}

void CSaveDiary::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSaveDiary, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSaveDiary::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSaveDiary::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSaveDiary 消息处理程序


void CSaveDiary::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CDailyApp*)AfxGetApp())->str == _T(""))
	{
		AfxMessageBox("请输入标题~");
		CSaveDiary::EndDialog(IDD_DIALOG1);
	}
	else
	{
		CString strFileName(_T(""));

		strFileName = ((CDailyApp*)AfxGetApp())->str;
		strFileName = strFileName + ".txt";
		try
		{
			CStdioFile file;
			file.Open(strFileName, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
			file.WriteString(((CDailyApp*)AfxGetApp())->strFile);
			file.Close();
		}
		catch (CFileException *e)
		{
			e->ReportError();
			e->Delete();
		}
		CDialog::EndDialog(IDD_EDITDIARY);
		CSaveDiary::EndDialog(IDD_DIALOG1);
	}
}


void CSaveDiary::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::EndDialog(IDD_EDITDIARY);
	CSaveDiary::EndDialog(IDD_DIALOG1);
}
