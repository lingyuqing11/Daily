// SaveDiary.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Daily.h"
#include "SaveDiary.h"
#include "afxdialogex.h"


// CSaveDiary �Ի���

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


// CSaveDiary ��Ϣ�������


void CSaveDiary::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (((CDailyApp*)AfxGetApp())->str == _T(""))
	{
		AfxMessageBox("���������~");
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::EndDialog(IDD_EDITDIARY);
	CSaveDiary::EndDialog(IDD_DIALOG1);
}
