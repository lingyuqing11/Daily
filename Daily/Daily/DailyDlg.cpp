
// DailyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Daily.h"
#include "DailyDlg.h"
#include "afxdialogex.h"
#include "MusicDlg.h"
#include "RijiDlg.h"
#include "HelpDlg.h"
#include "ScheduleDlg.h"
#include "HolidayDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDailyDlg �Ի���




CDailyDlg::CDailyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDailyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDailyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mylist);
	DDX_Control(pDX, IDC_MONTHCALENDAR1, mycalendar);
}

BEGIN_MESSAGE_MAP(CDailyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CDailyDlg::OnEnChangeEdit1)
	ON_NOTIFY(MCN_SELCHANGE, IDC_MONTHCALENDAR1, &CDailyDlg::OnMcnSelchangeMonthcalendar1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDailyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDailyDlg::OnBnClickedButton1)
	ON_COMMAND(ID_32775, &CDailyDlg::On32775)
	ON_BN_CLICKED(IDI_ICON8, &CDailyDlg::OnBnClickedIcon8)
	ON_BN_CLICKED(IDI_ICON3, &CDailyDlg::OnBnClickedIcon3)
	ON_BN_CLICKED(IDI_ICON6, &CDailyDlg::OnBnClickedIcon6)
	ON_BN_CLICKED(IDI_ICON4, &CDailyDlg::OnBnClickedIcon4)
	ON_BN_CLICKED(IDI_ICON9, &CDailyDlg::OnBnClickedIcon9)
	ON_BN_CLICKED(IDI_ICON7, &CDailyDlg::OnBnClickedIcon7)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CDailyDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CDailyDlg ��Ϣ�������

BOOL CDailyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��


	m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC)
	;//����������
	m_ToolBar.LoadToolBar(IDR_TOOLBAR1);


	m_ImageList.Create(32, 32, ILC_COLOR32 | ILC_MASK,0, 0);	//����ͼ���б�																//��ͼ���б������ͼ��
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON9));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON7));

	
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList) ;	//����ͼ���б�
	m_ToolBar.SetButtons(NULL, 8);					//��9����ť
																								//����ÿ����������ť��IDֵ����ʾ����
	m_ToolBar.SetButtonInfo(0, IDI_ICON1, TBSTYLE_BUTTON, 0);
	m_ToolBar.SetButtonText(0, "��ҳ");
	m_ToolBar.SetButtonInfo(1, IDI_ICON2, TBSTYLE_BUTTON, 1);
	m_ToolBar.SetButtonText(1, "����");
	m_ToolBar.SetButtonInfo(2, IDI_ICON3, TBSTYLE_BUTTON, 2);
	m_ToolBar.SetButtonText(2, "�ռ�");
	m_ToolBar.SetButtonInfo(3, IDI_ICON4, TBSTYLE_BUTTON, 3);
	m_ToolBar.SetButtonText(3, "�ճ�");
	m_ToolBar.SetButtonInfo(4, IDI_ICON9, TBSTYLE_BUTTON, 4);
	m_ToolBar.SetButtonText(4, "����");

	m_ToolBar.SetButtonInfo(5, IDI_ICON8, TBSTYLE_BUTTON, 5);
	m_ToolBar.SetButtonText(5, "����");
	m_ToolBar.SetButtonInfo(6, IDI_ICON6, TBSTYLE_BUTTON, 6);
	m_ToolBar.SetButtonText(6, "����");
	m_ToolBar.SetButtonInfo(7, IDI_ICON7, TBSTYLE_BUTTON, 7);
	m_ToolBar.SetButtonText(7, "�˳�");
	m_ToolBar.SetSizes(CSize(70,60), CSize(32, 32));//���ð�ť��С
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_PANE_LAST,0);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	/******************************************************************************************/
	//��ʼ���б�ؼ�����ʽ
	CRect rect;
	mylist.GetClientRect(&rect); //��ȡ����rect
	mylist.SetExtendedStyle(mylist.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT); //���÷��
	mylist.InsertColumn(1,_T("���ȼ�"),LVCFMT_CENTER,rect.Width()/8);//����Ϊ����0�п�ʼ����0�е����֣����÷���еĿ��
	mylist.InsertColumn(2,_T("����"),LVCFMT_CENTER,rect.Width()/4);
	mylist.InsertColumn(3,_T("����"),LVCFMT_CENTER,rect.Width()/4);
	mylist.InsertColumn(4,_T("��ϸ"),LVCFMT_CENTER,3*(rect.Width()/8));
	
	//��ʾ�����б�����
	n_Rec.CreateInstance(_uuidof(Recordset));
	//��ѯ���ݿ��е�Tra_info��
	n_Rec->Open("SELECT*FROM NoticeT",theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	int i=0;
	while(!n_Rec->adoEOF)
	{
		
		mylist.InsertItem(i,_T(""));
		mylist.SetItemText(i,0,(CString)n_Rec->GetCollect(_T("importance")));
		mylist.SetItemText(i,1,(CString)n_Rec->GetCollect(_T("ndate")));
		mylist.SetItemText(i,2,(CString)n_Rec->GetCollect(_T("title")));
		mylist.SetItemText(i,3,(CString)n_Rec->GetCollect(_T("detail")));
		n_Rec->MoveNext();
		++i;
	}
	n_Rec->Close();

	//��ʼ��gloMonth
	UINT sysMonth;
	CTime tm;
	CString str;
	tm=CTime::GetCurrentTime();
	sysMonth=tm.GetMonth();
	gloMonth=sysMonth;
/**********************************************************************************************************/
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDailyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDailyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();

		CPaintDC  dc(this);
		CRect  rect;
		GetClientRect(&rect);
		CDC  dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap  bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP3);
		//IDB_BITMAP�����Լ���ͼ��Ӧ��ID
		BITMAP  bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap  *pbmpOld = dcMem.SelectObject(&bmpBackground); dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0,
		bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDailyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CDailyDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

/**********************************************************************************************/
void CDailyDlg::OnMcnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTime time ;
	((CMonthCalCtrl*)GetDlgItem(IDC_MONTHCALENDAR1))->GetCurSel(time);  
	UINT nYear,nMonth,nDay;
	nYear   =  time.GetYear();
	nMonth  =  time.GetMonth();
	nDay    =  time.GetDay(); 
	CString date;
	date.Format(_T("%d/%d/%d"),nYear,nMonth,nDay);
	//AfxMessageBox(str);
	if(nMonth==gloMonth)
	{
	CString sql=(CString)"SELECT*FROM NoticeT WHERE ndate='" + date + (CString)"'";
	BSTR bsql=sql.AllocSysString();
	try
	{   //��ȡ�������ݼ�
		n_Rec->Open(bsql, theApp.m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
		SysFreeString(bsql); //ʹ��֮���ͷŸ���ʱת���ı���
	}
	catch (_com_error e1)
	{
		AfxMessageBox(_T("SQL������"), MB_OK);
		exit(0);
	}
	int i = 0,flag=0;
	//��ʾ�ռ��б�
	mylist.DeleteAllItems(); //����б��е�ԭ������

	while (!n_Rec->adoEOF)
	{
		flag = 1;
		mylist.InsertItem(i, _T(""));
		try
		{
			mylist.SetItemText(i, 0, (CString)n_Rec->GetCollect(_T("importance")));
			mylist.SetItemText(i, 1, (CString)n_Rec->GetCollect(_T("ndate")));
			mylist.SetItemText(i, 2, (CString)n_Rec->GetCollect(_T("title")));
			mylist.SetItemText(i, 3, (CString)n_Rec->GetCollect(_T("detail")));
		}
		catch (_com_error e2)
		{
			AfxMessageBox(_T("�����ݿ��ȡ���ݴ���"), MB_OK);
			exit(0);
		}
		n_Rec->MoveNext();
		++i;
	}
	if (flag == 0)
	{
		MessageBox(_T("��һ��û���ճ̣����Ժú���Ϣ��"));
	}
	date.ReleaseBuffer();
	n_Rec->Close();
	}
	else
		gloMonth=nMonth;

	*pResult = 0;
}


void CDailyDlg::OnBnClickedButton2()//�����ȼ����ֽ�������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString sql=(CString)"SELECT*FROM NoticeT ORDER BY importance DESC";
	BSTR bsql=sql.AllocSysString();
	try
	{   //��ȡ�������ݼ�
		n_Rec->Open(bsql, theApp.m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
		SysFreeString(bsql); //ʹ��֮���ͷŸ���ʱת���ı���
	}
	catch (_com_error e1)
	{
		AfxMessageBox(_T("SQL������"), MB_OK);
		exit(0);
	}

	//��ʾ�ռ��б�
	int i = 0;
	mylist.DeleteAllItems(); //����б��е�ԭ������

	while (!n_Rec->adoEOF)
	{
		
		mylist.InsertItem(i, _T(""));
		try
		{
			mylist.SetItemText(i, 0, (CString)n_Rec->GetCollect(_T("importance")));
			mylist.SetItemText(i, 1, (CString)n_Rec->GetCollect(_T("ndate")));
			mylist.SetItemText(i, 2, (CString)n_Rec->GetCollect(_T("title")));
			mylist.SetItemText(i, 3, (CString)n_Rec->GetCollect(_T("detail")));
		}
		catch (_com_error e2)
		{
			AfxMessageBox(_T("�����ݿ��ȡ���ݴ���"), MB_OK);
			exit(0);
		}
		n_Rec->MoveNext();
		++i;
	}
	
	sql.ReleaseBuffer();
	n_Rec->Close();
}


void CDailyDlg::OnBnClickedButton1()  //��ʱ������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString sql=(CString)"SELECT*FROM NoticeT ORDER BY ndate";
	BSTR bsql=sql.AllocSysString();
	try
	{   //��ȡ�������ݼ�
		n_Rec->Open(bsql, theApp.m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
		SysFreeString(bsql); //ʹ��֮���ͷŸ���ʱת���ı���
	}
	catch (_com_error e1)
	{
		AfxMessageBox(_T("SQL������"), MB_OK);
		exit(0);
	}

	//��ʾ�ռ��б�
	int i = 0;
	mylist.DeleteAllItems(); //����б��е�ԭ������

	while (!n_Rec->adoEOF)
	{
		
		mylist.InsertItem(i, _T(""));
		try
		{
			mylist.SetItemText(i, 0, (CString)n_Rec->GetCollect(_T("importance")));
			mylist.SetItemText(i, 1, (CString)n_Rec->GetCollect(_T("ndate")));
			mylist.SetItemText(i, 2, (CString)n_Rec->GetCollect(_T("title")));
			mylist.SetItemText(i, 3, (CString)n_Rec->GetCollect(_T("detail")));
		}
		catch (_com_error e2)
		{
			AfxMessageBox(_T("�����ݿ��ȡ���ݴ���"), MB_OK);
			exit(0);
		}
		n_Rec->MoveNext();
		++i;
	}
	
	sql.ReleaseBuffer();
	n_Rec->Close();
}

/*****************************************************************************************************/
void CDailyDlg::On32775()  //���������ֽ���
{

	// TODO: �ڴ���������������
	CMusicDlg dlg;
	dlg.DoModal();
}



void CDailyDlg::OnBnClickedIcon8()
{
		CMusicDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDailyDlg::OnBnClickedIcon3()
{
	CRijiDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDailyDlg::OnBnClickedIcon6()
{
    CHelpDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDailyDlg::OnBnClickedIcon4()
{
	CScheduleDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDailyDlg::OnBnClickedIcon9()
{
	CHolidayDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDailyDlg::OnBnClickedIcon7()
{
	exit(0);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

/*******************************************************************************************/
void CDailyDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NMLISTVIEW *pnml = (NMLISTVIEW*)pNMHDR;
	if (-1 != pnml->iItem)
	{
		CString str;
		CString title= mylist.GetItemText(pnml->iItem, 2);
		CString content= mylist.GetItemText(pnml->iItem, 3);
		str = (CString)"���⣺"+ title + "\r\n" +(CString)"���ݣ�"+ content;
		this->SetDlgItemText(IDC_EDIT1, str);
	}
	
	*pResult = 0;
}
/****************************************************************************/