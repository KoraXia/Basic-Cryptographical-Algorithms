// RSADlg.cpp : implementation file
//

#include "stdafx.h"
#include "RSA.h"
#include "RSADlg.h"
/////////////////////////////////////////////////////////////////////////////
#include "bignum.h"

static char pubkey[300]; // 公钥
static char pubmod[300]; // 公钥
static char prikey[300]; // 私钥
static char encrypt_text[300]; // 输出的密文
static unsigned int encrypt_len;
/////////////////////////////////////////////////////////////////////////////

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
	SetDlgItemText(IDC_EDIT1,NULL);
	SetDlgItemText(IDC_EDIT2,NULL);
	SetDlgItemText(IDC_EDIT3,NULL);
	SetDlgItemText(IDC_EDIT4,NULL);
	SetDlgItemText(IDC_EDIT5,NULL);
	SetDlgItemText(IDC_EDIT6,NULL);
}

void CRSADlg::OnDecrypt() 
{
	// TODO: Add your control notification handler code here
	unsigned int decrypt_len;
	// 输出的解密文
	char decrypt_text[300]; 
	// 使用RSA进行解密
	RSADecrypt(decrypt_text,&decrypt_len,encrypt_text,encrypt_len);
	
	m_decrypt=decrypt_text;
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_decrypt);
}

void CRSADlg::OnEncrypt() 
{
	// TODO: Add your control notification handler code here			
	char plain_text[300];
	int i;
    
	for (i=0;i<300;i++) {
	   plain_text[i] = 0;
	}

	UpdateData();
	strcpy(plain_text,m_plain);
	GenerateKeys(strMod,strPubKey,strPriKey,16);// 产生公钥和私钥
	// 设置公钥和私钥字符串，这里转换成char型的是为了在网络上传输方便
	memcpy(pubkey,(const char*)strPubKey,strlen((const char*)strPubKey)+1);
	memcpy(pubmod,(const char*)strMod,strlen((const char*)strMod)+1);
	memcpy(prikey,(const char*)strPriKey,strlen((const char*)strPriKey)+1);
    // 使用RSA进行加密
	RSAEncrypt(pubkey,pubmod,encrypt_text,&encrypt_len,plain_text,sizeof(plain_text));

	m_pube=pubkey;
	m_pubn=pubmod;
	m_prid=prikey;
	m_encrypt=encrypt_text;
	GetDlgItem(IDC_EDIT2)->SetWindowText(m_pubn);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_pube);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_prid);
	GetDlgItem(IDC_EDIT5)->SetWindowText(m_encrypt);
}