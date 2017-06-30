// MusicDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Daily.h"
#include "MusicDlg.h"
#include "afxdialogex.h"


// CMusicDlg 对话框

IMPLEMENT_DYNAMIC(CMusicDlg, CDialogEx)

CMusicDlg::CMusicDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMusicDlg::IDD, pParent)
{

}

CMusicDlg::~CMusicDlg()
{
}

void CMusicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMusicDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMusicDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMusicDlg 消息处理程序


void CMusicDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CFileDialog dlg(TRUE, "ifo", "", OFN_HIDEREADONLY, "音乐(*.mp3)|*.mp3||");
	if (IDCANCEL == dlg.DoModal()) {
		return;
	}
	// 取得要操作文件的路径  
	CString filename = dlg.GetPathName();
	CString name = dlg.GetFileTitle();
	CFile file;
	// 读出来的东西必须与结构体的大小相匹配，不匹配，要么读完，要么读取出错  
	if (!file.Open(filename, CFile::modeRead | CFile::shareDenyNone)) {
		AfxMessageBox("打开文件失败");
		return;
	}
	GetDlgItem(IDC_MUSIC2)->SetWindowText(name);
	CString str;
	file.Close();
}
