// RijiDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Daily.h"
#include "RijiDlg.h"
#include "afxdialogex.h"
#include "EditDiaryDlg.h"


// CRijiDlg �Ի���

IMPLEMENT_DYNAMIC(CRijiDlg, CDialogEx)


BOOL CRijiDlg::OnInitDialog()
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
	mylist.InsertColumn(1, _T("����"), LVCFMT_CENTER, rect.Width());
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

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
	DDX_Control(pDX, IDC_LIST2, mylist);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_DateCtrl);
}


BEGIN_MESSAGE_MAP(CRijiDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &CRijiDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CRijiDlg::OnEnChangeEdit4)
	ON_LBN_SELCHANGE(IDC_LIST1, &CRijiDlg::OnLbnSelchangeList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CRijiDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON2, &CRijiDlg::OnBnClickedButton2)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CRijiDlg::OnDtnDatetimechangeDatetimepicker1)
	ON_BN_CLICKED(IDC_BUTTON1, &CRijiDlg::OnBnClickedButton1)
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
	CString str;
	NMLISTVIEW *pnml = (NMLISTVIEW*)pNMHDR; //������pNMHDR��Ϊ��һ���ṹ�����չ�ṹ
	if (-1 != pnml->iItem) //�����ȡ���˸ýṹ
	{
		str = mylist.GetItemText(pnml->iItem, 0); //��ȡѡ���еĵڶ������ݣ�����str																		  //this->SetDlgItemText(IDC_STATIC2, str);   //����idΪIDC_EDIT1���ı�������Ϊstr
	}
	if (str == "")
		return;
	else
	{
		SetDlgItemText(IDC_EDIT3, str);
		CString fileName = "Diary/" + str + ".txt";

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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

CString CRijiDlg::DataDeleteZero(CString DATA)
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTime time;
	m_DateCtrl.GetTime(time);
	CString strTime = time.Format("%Y/%m/%d");
	strTime = DataDeleteZero(strTime);

	*pResult = 0;
}


void CRijiDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strText(_T(""));
	CString strTitle(_T(""));
	GetDlgItemText(IDC_EDIT4, strText);
	GetDlgItemText(IDC_EDIT3, strTitle);
	try
	{
		CStdioFile file;
		CString fileName;
		fileName = "Diary/" + strTitle + ".txt";
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
