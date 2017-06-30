// ScheduleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Daily.h"
#include "ScheduleDlg.h"
#include "afxdialogex.h"


// CScheduleDlg 对话框

IMPLEMENT_DYNAMIC(CScheduleDlg, CDialogEx)

CScheduleDlg::CScheduleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScheduleDlg::IDD, pParent)
{

}

CScheduleDlg::~CScheduleDlg()
{
}

void CScheduleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CScheduleDlg, CDialogEx)
END_MESSAGE_MAP()


// CScheduleDlg 消息处理程序
