// PRIMEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PRIME.h"
#include "PRIMEDlg.h"
#include "math.h"
#include "time.h"

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
// CPRIMEDlg dialog

CPRIMEDlg::CPRIMEDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPRIMEDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPRIMEDlg)
	m_prime = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPRIMEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPRIMEDlg)
	DDX_Text(pDX, IDC_PRIME, m_prime);
	DDV_MaxChars(pDX, m_prime, 10);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPRIMEDlg, CDialog)
	//{{AFX_MSG_MAP(CPRIMEDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEAN, OnClean)
	ON_BN_CLICKED(IDC_EXAM, OnExam)
	ON_BN_CLICKED(IDC_BUTTON1, OnExam2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPRIMEDlg message handlers

BOOL CPRIMEDlg::OnInitDialog()
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

void CPRIMEDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPRIMEDlg::OnPaint() 
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
HCURSOR CPRIMEDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPRIMEDlg::OnClean() 
{
	// TODO: 编程实现
    SetDlgItemText(IDC_PRIME, NULL);
	SetDlgItemText(IDC_TIME, NULL);
	
    SetDlgItemText(IDC_EDIT1, NULL);
}

void CPRIMEDlg::OnExam() 
{
	// TODO: Add your control notification handler code here
	unsigned long n;
	long beginTime, endTime;
	int result;
	unsigned int k=0;  //k是Miller-Rabin算法重复执行的次数

	// 从界面中输入待检测的数据
	n = GetDlgItemInt(IDC_PRIME);
    k = GetDlgItemInt(IDC_EDIT1);
    //参照OnExam2函数获取执行时间，并在控件IDC_TIME上显示
    beginTime = clock();
	//...... 
	result = MillerRabin(n,6542,k);
    //......
	endTime = clock();
    SetDlgItemInt(IDC_TIME,endTime-beginTime);

	if (result == 0)
	{
		MessageBox("不是素数!");
	}
	else 
	{
		MessageBox("是素数!");
	}
	

}



void CPRIMEDlg::OnExam2() 
{
	// TODO: Add your control notification handler code here

	unsigned long n;
	long beginTime, endTime;
	int result;
	
	// 从界面中输入待检测的数据
	n = GetDlgItemInt(IDC_PRIME);

    beginTime = clock();  //获取开始时间，单位为毫秒

	result = Eratosthenes(n);

	endTime = clock();  //获取结束时间，单位为毫秒

	SetDlgItemInt(IDC_TIME,endTime-beginTime);

	if (result == 0)
	{
		MessageBox("不是素数!");
	}
	else 
	{
		MessageBox("是素数!");
	}

}

