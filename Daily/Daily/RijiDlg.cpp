// RijiDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Daily.h"
#include "RijiDlg.h"
#include "afxdialogex.h"
#include "EditDiaryDlg.h"


// CRijiDlg �Ի���

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


// CRijiDlg ��Ϣ�������


void CRijiDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CRijiDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CRijiDlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CRijiDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CRijiDlg::OnBnClickedButton2()
{
	CEditDiaryDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

