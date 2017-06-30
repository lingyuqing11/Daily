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
END_MESSAGE_MAP()


// CEditDiaryDlg 消息处理程序
