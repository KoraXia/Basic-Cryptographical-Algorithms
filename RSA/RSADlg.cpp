// RSADlg.cpp : implementation file
//

#include "stdafx.h"
#include "RSA.h"
#include "RSADlg.h"
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
extern void RSAEncrypt(unsigned long publickey, unsigned long publicmod, unsigned long *output, unsigned long input);
extern void RSADecrypt(unsigned long privateKey, unsigned long publicmod, unsigned long *output, unsigned long input);
extern void GenKeyPair(unsigned long &publicmod, unsigned long &publickey, unsigned long &privatekey);

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
// CRSADlg dialog

CRSADlg::CRSADlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRSADlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRSADlg)
	m_plain = _T("");
	m_pubn = _T("");
	m_pube = _T("");
	m_prid = _T("");
	m_encrypt = _T("");
	m_decrypt = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRSADlg)
	DDX_Text(pDX, IDC_EDIT1, m_plain);
	DDX_Text(pDX, IDC_EDIT2, m_pubn);
	DDX_Text(pDX, IDC_EDIT3, m_pube);
	DDX_Text(pDX, IDC_EDIT4, m_prid);
	DDX_Text(pDX, IDC_EDIT5, m_encrypt);
	DDX_Text(pDX, IDC_EDIT6, m_decrypt);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRSADlg, CDialog)
	//{{AFX_MSG_MAP(CRSADlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEAN, OnClean)
	ON_BN_CLICKED(IDC_DECRYPT, OnDecrypt)
	ON_BN_CLICKED(IDC_ENCRYPT, OnEncrypt)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT1, &CRSADlg::OnEnChangeEdit1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRSADlg message handlers

BOOL CRSADlg::OnInitDialog()
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

void CRSADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRSADlg::OnPaint() 
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
HCURSOR CRSADlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRSADlg::OnClean() 
{
	// TODO: Add your control notification handler code here
    //补充代码
	SetDlgItemText(IDC_EDIT1, NULL);
	SetDlgItemText(IDC_EDIT2, NULL);
	SetDlgItemText(IDC_EDIT3, NULL);
	SetDlgItemText(IDC_EDIT4, NULL);
	SetDlgItemText(IDC_EDIT5, NULL);
	SetDlgItemText(IDC_EDIT6, NULL);

}

void CRSADlg::OnEncrypt() 
{
	// TODO: Add your control notification handler code here			
	unsigned long plain, n, e, d,result;
	plain = GetDlgItemInt(IDC_EDIT1);
     /*  n = GetDlgItemInt(IDC_EDIT2);
	e = GetDlgItemInt(IDC_EDIT3);
	d = GetDlgItemInt(IDC_EDIT4);
	*/
	  GenKeyPair(n, e, d);
	  RSAEncrypt(e, n, &result, plain);

	  SetDlgItemInt(IDC_EDIT2,n); 
      SetDlgItemInt(IDC_EDIT3,e); 
	  SetDlgItemInt(IDC_EDIT4,d); 


	  SetDlgItemInt(IDC_EDIT5,result); 
}

void CRSADlg::OnDecrypt() 
{
	// TODO: Add your control notification handler code here
	unsigned long result;
	unsigned long  n, e, d, code;
	n = GetDlgItemInt(IDC_EDIT2);
	e = GetDlgItemInt(IDC_EDIT3);
	d = GetDlgItemInt(IDC_EDIT4);
	code = GetDlgItemInt(IDC_EDIT5);
    // 补充代码
	RSADecrypt(d, n, &result, code);
	
    SetDlgItemInt(IDC_EDIT6,result); 
}



void CRSADlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
