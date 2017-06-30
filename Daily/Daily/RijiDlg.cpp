// RijiDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Daily.h"
#include "RijiDlg.h"
#include "afxdialogex.h"
#include "EditDiaryDlg.h"


// CRijiDlg 对话框

IMPLEMENT_DYNAMIC(CRijiDlg, CDialogEx)

CRijiDlg::CRijiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRijiDlg::IDD, pParent)
{

}

CRijiDlg::~CRijiDlg()
{
}

void CRijiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRijiDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &CRijiDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CRijiDlg::OnEnChangeEdit4)
	ON_LBN_SELCHANGE(IDC_LIST1, &CRijiDlg::OnLbnSelchangeList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CRijiDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON2, &CRijiDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CRijiDlg 消息处理程序


void CRijiDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CRijiDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CRijiDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CRijiDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CRijiDlg::OnBnClickedButton2()
{
	CEditDiaryDlg dlg;
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}

