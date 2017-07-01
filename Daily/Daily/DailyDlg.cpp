
// DailyDlg.cpp : 实现文件
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



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CDailyDlg 对话框




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


// CDailyDlg 消息处理程序

BOOL CDailyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC)
	;//创建工具栏
	m_ToolBar.LoadToolBar(IDR_TOOLBAR1);


	m_ImageList.Create(32, 32, ILC_COLOR32 | ILC_MASK,0, 0);	//创建图像列表																//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON9));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON7));

	
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList) ;	//关联图像列表
	m_ToolBar.SetButtons(NULL, 8);					//共9个按钮
																								//设置每个工具栏按钮的ID值和显示文字
	m_ToolBar.SetButtonInfo(0, IDI_ICON1, TBSTYLE_BUTTON, 0);
	m_ToolBar.SetButtonText(0, "主页");
	m_ToolBar.SetButtonInfo(1, IDI_ICON2, TBSTYLE_BUTTON, 1);
	m_ToolBar.SetButtonText(1, "设置");
	m_ToolBar.SetButtonInfo(2, IDI_ICON3, TBSTYLE_BUTTON, 2);
	m_ToolBar.SetButtonText(2, "日记");
	m_ToolBar.SetButtonInfo(3, IDI_ICON4, TBSTYLE_BUTTON, 3);
	m_ToolBar.SetButtonText(3, "日程");
	m_ToolBar.SetButtonInfo(4, IDI_ICON9, TBSTYLE_BUTTON, 4);
	m_ToolBar.SetButtonText(4, "节日");

	m_ToolBar.SetButtonInfo(5, IDI_ICON8, TBSTYLE_BUTTON, 5);
	m_ToolBar.SetButtonText(5, "音乐");
	m_ToolBar.SetButtonInfo(6, IDI_ICON6, TBSTYLE_BUTTON, 6);
	m_ToolBar.SetButtonText(6, "帮助");
	m_ToolBar.SetButtonInfo(7, IDI_ICON7, TBSTYLE_BUTTON, 7);
	m_ToolBar.SetButtonText(7, "退出");
	m_ToolBar.SetSizes(CSize(70,60), CSize(32, 32));//设置按钮大小
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_PANE_LAST,0);

	// TODO: 在此添加额外的初始化代码
	/******************************************************************************************/
	//初始化列表控件的样式
	CRect rect;
	mylist.GetClientRect(&rect); //获取变量rect
	mylist.SetExtendedStyle(mylist.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT); //设置风格
	mylist.InsertColumn(1,_T("优先级"),LVCFMT_CENTER,rect.Width()/8);//参数为：从0列开始，第0列的名字，设置风格，列的宽度
	mylist.InsertColumn(2,_T("日期"),LVCFMT_CENTER,rect.Width()/4);
	mylist.InsertColumn(3,_T("标题"),LVCFMT_CENTER,rect.Width()/4);
	mylist.InsertColumn(4,_T("详细"),LVCFMT_CENTER,3*(rect.Width()/8));
	
	//显示提醒列表内容
	n_Rec.CreateInstance(_uuidof(Recordset));
	//查询数据库中的Tra_info表
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

	//初始化gloMonth
	UINT sysMonth;
	CTime tm;
	CString str;
	tm=CTime::GetCurrentTime();
	sysMonth=tm.GetMonth();
	gloMonth=sysMonth;
/**********************************************************************************************************/
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDailyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
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
		//IDB_BITMAP是你自己的图对应的ID
		BITMAP  bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap  *pbmpOld = dcMem.SelectObject(&bmpBackground); dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0,
		bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDailyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CDailyDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

/**********************************************************************************************/
void CDailyDlg::OnMcnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
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
	{   //获取各个数据集
		n_Rec->Open(bsql, theApp.m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
		SysFreeString(bsql); //使用之后释放该临时转化的变量
	}
	catch (_com_error e1)
	{
		AfxMessageBox(_T("SQL语句错误"), MB_OK);
		exit(0);
	}
	int i = 0,flag=0;
	//显示日记列表
	mylist.DeleteAllItems(); //清空列表中的原有内容

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
			AfxMessageBox(_T("从数据库获取数据错误"), MB_OK);
			exit(0);
		}
		n_Rec->MoveNext();
		++i;
	}
	if (flag == 0)
	{
		MessageBox(_T("这一天没有日程，可以好好休息了"));
	}
	date.ReleaseBuffer();
	n_Rec->Close();
	}
	else
		gloMonth=nMonth;

	*pResult = 0;
}


void CDailyDlg::OnBnClickedButton2()//按优先级数字降序排序
{
	// TODO: 在此添加控件通知处理程序代码
	CString sql=(CString)"SELECT*FROM NoticeT ORDER BY importance DESC";
	BSTR bsql=sql.AllocSysString();
	try
	{   //获取各个数据集
		n_Rec->Open(bsql, theApp.m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
		SysFreeString(bsql); //使用之后释放该临时转化的变量
	}
	catch (_com_error e1)
	{
		AfxMessageBox(_T("SQL语句错误"), MB_OK);
		exit(0);
	}

	//显示日记列表
	int i = 0;
	mylist.DeleteAllItems(); //清空列表中的原有内容

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
			AfxMessageBox(_T("从数据库获取数据错误"), MB_OK);
			exit(0);
		}
		n_Rec->MoveNext();
		++i;
	}
	
	sql.ReleaseBuffer();
	n_Rec->Close();
}


void CDailyDlg::OnBnClickedButton1()  //按时间排序
{
	// TODO: 在此添加控件通知处理程序代码
	CString sql=(CString)"SELECT*FROM NoticeT ORDER BY ndate";
	BSTR bsql=sql.AllocSysString();
	try
	{   //获取各个数据集
		n_Rec->Open(bsql, theApp.m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
		SysFreeString(bsql); //使用之后释放该临时转化的变量
	}
	catch (_com_error e1)
	{
		AfxMessageBox(_T("SQL语句错误"), MB_OK);
		exit(0);
	}

	//显示日记列表
	int i = 0;
	mylist.DeleteAllItems(); //清空列表中的原有内容

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
			AfxMessageBox(_T("从数据库获取数据错误"), MB_OK);
			exit(0);
		}
		n_Rec->MoveNext();
		++i;
	}
	
	sql.ReleaseBuffer();
	n_Rec->Close();
}

/*****************************************************************************************************/
void CDailyDlg::On32775()  //打开设置音乐界面
{

	// TODO: 在此添加命令处理程序代码
	CMusicDlg dlg;
	dlg.DoModal();
}



void CDailyDlg::OnBnClickedIcon8()
{
		CMusicDlg dlg;
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CDailyDlg::OnBnClickedIcon3()
{
	CRijiDlg dlg;
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CDailyDlg::OnBnClickedIcon6()
{
    CHelpDlg dlg;
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CDailyDlg::OnBnClickedIcon4()
{
	CScheduleDlg dlg;
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CDailyDlg::OnBnClickedIcon9()
{
	CHolidayDlg dlg;
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CDailyDlg::OnBnClickedIcon7()
{
	exit(0);
	// TODO: 在此添加控件通知处理程序代码
}

/*******************************************************************************************/
void CDailyDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NMLISTVIEW *pnml = (NMLISTVIEW*)pNMHDR;
	if (-1 != pnml->iItem)
	{
		CString str;
		CString title= mylist.GetItemText(pnml->iItem, 2);
		CString content= mylist.GetItemText(pnml->iItem, 3);
		str = (CString)"标题："+ title + "\r\n" +(CString)"内容："+ content;
		this->SetDlgItemText(IDC_EDIT1, str);
	}
	
	*pResult = 0;
}
/****************************************************************************/