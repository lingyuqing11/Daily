
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
	//m_ToolBar.EnableDocking(CBRS_ALIGN_ANY);


	m_ImageList.Create(32, 32, ILC_COLOR32 | ILC_MASK,0, 0);	//创建图像列表																//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON7));
	//m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	//m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON9));

	
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList) ;	//关联图像列表
	m_ToolBar.SetButtons(NULL, 7);					//共9个按钮
																								//设置每个工具栏按钮的ID值和显示文字
	m_ToolBar.SetButtonInfo(0, IDI_ICON1, TBSTYLE_BUTTON, 0);
	m_ToolBar.SetButtonText(0, "主页");
	m_ToolBar.SetButtonInfo(1, IDI_ICON2, TBSTYLE_BUTTON, 1);
	m_ToolBar.SetButtonText(1, "设置");
	m_ToolBar.SetButtonInfo(2, IDI_ICON3, TBSTYLE_BUTTON, 2);
	m_ToolBar.SetButtonText(2, "日记");
	m_ToolBar.SetButtonInfo(3, IDI_ICON4, TBSTYLE_BUTTON, 3);
	m_ToolBar.SetButtonText(3, "日程");
	m_ToolBar.SetButtonInfo(4, IDI_ICON8, TBSTYLE_BUTTON, 4);
	m_ToolBar.SetButtonText(4, "音乐");
	m_ToolBar.SetButtonInfo(5, IDI_ICON6, TBSTYLE_BUTTON, 5);
	m_ToolBar.SetButtonText(5, "帮助");
	m_ToolBar.SetButtonInfo(6, IDI_ICON7, TBSTYLE_BUTTON, 6);
	m_ToolBar.SetButtonText(6, "退出");
	/*m_ToolBar.SetButtonInfo(7, IDC_BUTTON_HELP, TBSTYLE_BUTTON, 7);
	m_ToolBar.SetButtonText(7, "帮助");
	m_ToolBar.SetButtonInfo(8, IDC_BUTTON_EXIT, TBSTYLE_BUTTON, 8);
	m_ToolBar.SetButtonText(8, "退出");*/
	m_ToolBar.SetSizes(CSize(70,60), CSize(32, 32));//设置按钮大小
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_PANE_LAST,0);

	// TODO: 在此添加额外的初始化代码

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
		bmpBackground.LoadBitmap(IDB_BITMAP5);
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


void CDailyDlg::OnMcnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CDailyDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDailyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDailyDlg::On32775()
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
