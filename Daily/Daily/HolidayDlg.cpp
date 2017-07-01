// HolidayDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Daily.h"
#include "HolidayDlg.h"
#include "afxdialogex.h"


// CHolidayDlg 对话框

IMPLEMENT_DYNAMIC(CHolidayDlg, CDialogEx)


BOOL CHolidayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);


	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	CRect rect;
	mylist.GetClientRect(&rect);
	mylist.SetExtendedStyle(mylist.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);//具有线条--------

	mylist.InsertColumn(1, _T("日期"), LVCFMT_CENTER, rect.Width() / 4);
	mylist.InsertColumn(2, _T("节日"), LVCFMT_CENTER, rect.Width() / 4);
	mylist.InsertColumn(3, _T("简介"), LVCFMT_CENTER, rect.Width() / 2);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

CHolidayDlg::CHolidayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHolidayDlg::IDD, pParent)
{

}

CHolidayDlg::~CHolidayDlg()
{
}

void CHolidayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, mylist);
}


BEGIN_MESSAGE_MAP(CHolidayDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CHolidayDlg::OnLvnItemchangedList2)
END_MESSAGE_MAP()


// CHolidayDlg 消息处理程序


void CHolidayDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
