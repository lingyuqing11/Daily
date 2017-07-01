// EditDiaryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Daily.h"
#include "EditDiaryDlg.h"
#include "afxdialogex.h"
#include "SaveDiary.h"
#include "RijiDlg.h"

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
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_CtrlDate);
}


BEGIN_MESSAGE_MAP(CEditDiaryDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CEditDiaryDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CEditDiaryDlg::OnDtnDatetimechangeDatetimepicker1)
END_MESSAGE_MAP()


// CEditDiaryDlg 消息处理程序


void CEditDiaryDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strText(_T(""));
	CString strFileName(_T(""));
	GetDlgItemText(IDC_EDIT2, strText);
	GetDlgItemText(IDC_EDIT1, strFileName);
	if (strFileName == _T(""))
	{
		AfxMessageBox(_T("请输入标题~"));
	}
	else
	{
		strFileName = "Diary/" + strFileName + ".txt";
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
}


void CEditDiaryDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	GetDlgItemText(IDC_EDIT1, ((CDailyApp*)AfxGetApp())->str);
	GetDlgItemText(IDC_EDIT2, ((CDailyApp*)AfxGetApp())->strFile);
	if (((CDailyApp*)AfxGetApp())->str == _T("") && ((CDailyApp*)AfxGetApp())->strFile == _T(""))
	{
		CDialog::EndDialog(IDD_EDITDIARY);
	}
	else {
		CSaveDiary NDdlg;
		NDdlg.DoModal();
	}
	CDialogEx::OnClose();
}


void CEditDiaryDlg::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CTime time;
	m_CtrlDate.GetTime(time);
	CString strTime = time.Format("%Y/%m/%d");
	strTime = ((CRijiDlg*)AfxGetApp())->DataDeleteZero(strTime);

	*pResult = 0;
}
