// HolidayDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Daily.h"
#include "HolidayDlg.h"
#include "afxdialogex.h"


// CHolidayDlg �Ի���

IMPLEMENT_DYNAMIC(CHolidayDlg, CDialogEx)


BOOL CHolidayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);


	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��


	CRect rect;
	mylist.GetClientRect(&rect);
	mylist.SetExtendedStyle(mylist.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);//��������--------

	mylist.InsertColumn(1, _T("����"), LVCFMT_CENTER, rect.Width() / 4);
	mylist.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width() / 4);
	mylist.InsertColumn(3, _T("���"), LVCFMT_CENTER, rect.Width() / 2);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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


// CHolidayDlg ��Ϣ�������


void CHolidayDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
