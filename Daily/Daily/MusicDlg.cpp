// MusicDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Daily.h"
#include "MusicDlg.h"
#include "afxdialogex.h"


// CMusicDlg �Ի���

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


// CMusicDlg ��Ϣ�������


void CMusicDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CFileDialog dlg(TRUE, "ifo", "", OFN_HIDEREADONLY, "����(*.mp3)|*.mp3||");
	if (IDCANCEL == dlg.DoModal()) {
		return;
	}
	// ȡ��Ҫ�����ļ���·��  
	CString filename = dlg.GetPathName();
	CString name = dlg.GetFileTitle();
	CFile file;
	// �������Ķ���������ṹ��Ĵ�С��ƥ�䣬��ƥ�䣬Ҫô���꣬Ҫô��ȡ����  
	if (!file.Open(filename, CFile::modeRead | CFile::shareDenyNone)) {
		AfxMessageBox("���ļ�ʧ��");
		return;
	}
	GetDlgItem(IDC_MUSIC2)->SetWindowText(name);
	CString str;
	file.Close();
}
