// EUCINVDlg.cpp : implementation file
//


#include "stdafx.h"
#include "EUCINV.h"
#include "EUCINVDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEUCINVDlg dialog

CEUCINVDlg::CEUCINVDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEUCINVDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEUCINVDlg)
	m_a = _T("");
	m_m = _T("");
	m_i = _T("");
	m_gcd = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEUCINVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEUCINVDlg)
	DDX_Text(pDX, IDC_A, m_a);
	DDX_Text(pDX, IDC_M, m_m);
	DDX_Text(pDX, IDC_I, m_i);
	DDX_Text(pDX, IDC_GCD, m_gcd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEUCINVDlg, CDialog)
	//{{AFX_MSG_MAP(CEUCINVDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEUCINVDlg message handlers

BOOL CEUCINVDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEUCINVDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEUCINVDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEUCINVDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEUCINVDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	long a, n; 
	long *OutArr;  
	
	// 从界面中输入待检测的数据
	a = GetDlgItemInt(IDC_A);
	n = GetDlgItemInt(IDC_M);
	//a = 获取数值的函数(IDC_A);
    //n = 获取数值的函数(IDC_M);

    OutArr = inv(a,n);  //在inv.cpp文件中实现inv(a,n)
	SetDlgItemInt(IDC_GCD,OutArr[0]);
    SetDlgItemInt(IDC_I,OutArr[1]);
	if(OutArr[1]==0){
		AfxMessageBox("乘法逆元不存在");
	}
	//输出数值到界面的函数(IDC_GCD,OutArr[0]);
	//输出数值到界面的函数(IDC_I,OutArr[1]);
	
}

void CEUCINVDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
    //补充代码
	SetDlgItemText(IDC_A, NULL);
	SetDlgItemText(IDC_M, NULL);
	SetDlgItemText(IDC_GCD, NULL);
	SetDlgItemText(IDC_I, NULL);

}




      
     
 
 
