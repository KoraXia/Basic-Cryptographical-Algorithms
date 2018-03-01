// RANDOMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RANDOM.h"
#include "RANDOMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

unsigned long seedLCG=100; //存放LCG的种子
unsigned long seedBBS;
unsigned long x; //存放BBS的种子

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
// CRANDOMDlg dialog

CRANDOMDlg::CRANDOMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRANDOMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRANDOMDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRANDOMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRANDOMDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRANDOMDlg, CDialog)
	//{{AFX_MSG_MAP(CRANDOMDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, OnCancel1)
	ON_BN_CLICKED(IDCANCEL2, OnCancel2)
	ON_BN_CLICKED(IDOK, OnLCG)
	ON_BN_CLICKED(IDOK2, OnBBS)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRANDOMDlg message handlers

BOOL CRANDOMDlg::OnInitDialog()
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

void CRANDOMDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRANDOMDlg::OnPaint() 
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
HCURSOR CRANDOMDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRANDOMDlg::OnCancel1() 
{
	// TODO: Add your control notification handler code here
    //补充代码
	SetDlgItemText(IDC_EDIT1,NULL);
	SetDlgItemText(IDC_EDIT2,NULL);
	SetDlgItemText(IDC_EDIT3,NULL);
    SetDlgItemText(IDC_EDIT10,NULL);
	SetDlgItemText(IDC_EDIT7,NULL);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	inputflagLCG = 0;
	seedLCG = 0;
}

void CRANDOMDlg::OnCancel2() 
{
	// TODO: Add your control notification handler code here
    //补充代码
	SetDlgItemText(IDC_EDIT4,NULL);
	SetDlgItemText(IDC_EDIT5,NULL);
	SetDlgItemText(IDC_EDIT6,NULL);
    SetDlgItemText(IDC_EDIT11,NULL);
	GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(TRUE);
	inputflagLCG = 0;
	seedLCG = 0;
}

void CRANDOMDlg::OnLCG() 
{
	// TODO: Add your control notification handler code here
	unsigned long a, c, m;
	unsigned long result;
		
	// 从界面中输入待检测的数据

     a = GetDlgItemInt(IDC_EDIT1);
    
	 c = GetDlgItemInt(IDC_EDIT2);

	 m = GetDlgItemInt(IDC_EDIT3);
	 
 	 if (a == 0) 
	     a = 69069;  // a的缺省值为69069

     if (c == 0) 
	     c = 5;  // b的缺省值为5

     if (m == 0) 
	     m = 4294967295;  // m的缺省值为4294967295

    if (!inputflagLCG) {

	    GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);

	    GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);

	    GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);

	 //补充代码

	}
	 
	//补充代码

    result=randLCG(a, c, m, seedLCG);
	seedLCG=result;
	SetDlgItemInt(IDC_EDIT10,result);

}


void CRANDOMDlg::OnBBS() 
{
	// TODO: Add your control notification handler code here

	unsigned long p, q, s,n;
	unsigned long result;
    long *OutArr;
	
	// 从界面中输入待检测的数据

 	p = GetDlgItemInt(IDC_EDIT4);
    
	q = GetDlgItemInt(IDC_EDIT5);

	if (p == 0) 
		p = 383;  // p的缺省值为383

    if (q == 0) 
		q = 503;  // q的缺省值为503

    n = p*q;

   if (!inputflagBBS) {
        if (p%4 != 3) {
	        MessageBox("输入p模4不为3，请重新输入；或者缺省");
		    return;
		}
		if (q%4 != 3) {
	        MessageBox("输入q模4不为3，请重新输入；或者缺省");
		    return;
		}

        //补充代码

		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	    GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);

	    s = GetDlgItemInt(IDC_EDIT6);   
	    if (s == 0) {
			s=97;
        //补充代码，提供机器随机选择的、满足条件的数    
		}
        else {        
	 
		//OutArr = inv(s, n);

		//if (OutArr[0] != 1) {

		  //      MessageBox("gcd(s,pq)不为1，请重新输入s；或者缺省，将由系统自动选择");
		//		return;
		//	}
		}
	    GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
        seedBBS=s;
	    //补充代码
		inputflagBBS = 1;

   }
	result = randBBS(n,32);
	SetDlgItemInt(IDC_EDIT11,result);
}

void CRANDOMDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
	exit(0);
}
