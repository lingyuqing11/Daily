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
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_DateCtrl);
}


BEGIN_MESSAGE_MAP(CRijiDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &CRijiDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CRijiDlg::OnEnChangeEdit4)
	ON_LBN_SELCHANGE(IDC_LIST1, &CRijiDlg::OnLbnSelchangeList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CRijiDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON2, &CRijiDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CRijiDlg::OnBnClickedButton1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CRijiDlg::OnDtnDatetimechangeDatetimepicker1)
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
	CString str;
	NMLISTVIEW *pnml = (NMLISTVIEW*)pNMHDR; //访问由pNMHDR作为第一个结构体的扩展结构
	if (-1 != pnml->iItem) //如果获取到了该结构
	{
		str = m_list.GetItemText(pnml->iItem, 0); //获取选中行的第二列内容，送入str																		  //this->SetDlgItemText(IDC_STATIC2, str);   //设置id为IDC_EDIT1的文本框内容为str
	}
	if (str == "")
		return;
	else
	{
		SetDlgItemText(IDC_EDIT3, str);
		CString fileName = str + ".txt";

		CFile fFile(fileName, CFile::modeReadWrite);
		CStringA strFile;
		fFile.Read(strFile.GetBufferSetLength(fFile.GetLength()), fFile.GetLength());

		fFile.Close();
		strFile.ReleaseBuffer();
		SetDlgItemText(IDC_EDIT4, strFile);
	}
	*pResult = 0;
}


void CRijiDlg::OnBnClickedButton2()
{
	CEditDiaryDlg dlg;
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}



void CRijiDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strText(_T(""));
	CString strTitle(_T(""));
	GetDlgItemText(IDC_EDIT4, strText);
	GetDlgItemText(IDC_EDIT3, strTitle);
	try
	{
		CStdioFile file;
		CString fileName;
		fileName = strTitle + ".txt";
		file.Open(fileName, CFile::modeWrite);
		file.WriteString(strText);
		file.Flush();
		file.Close();
	}
	catch (CFileException* e)
	{
		e->ReportError();
		e->Delete();
	}
}

CString DataDeleteZero(CString DATA)
{
	CString strMonth, strDay, strYear;
	int year = 0, month = 0, day = 0;
	year = atoi(DATA.Mid(0, 4));
	month = atoi(DATA.Mid(5, 2));
	day = atoi(DATA.Mid(8, 2));
	if (month < 10)
		month = atoi(DATA.Mid(6, 2));
	if (day < 10)
		day = atoi(DATA.Mid(9, 2));
	strYear.Format("%d", year);
	strMonth.Format("%d", month);
	strDay.Format("%d", day);
	DATA = strYear + "/" + strMonth + "/" + strDay;
	return DATA;
}

void CRijiDlg::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CTime time;
	m_DateCtrl.GetTime(time);
	CString strTime = time.Format("%Y/%m/%d");

	strTime = DataDeleteZero(strTime);

	*pResult = 0;
}
