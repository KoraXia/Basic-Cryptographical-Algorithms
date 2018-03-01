// DESDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DES.h"
#include "DESDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


static char encrypt_text[256];//保存加密后的结果；也用于存放中间结果

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
// CDESDlg dialog

CDESDlg::CDESDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDESDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDESDlg)
	m_plain = _T("");
	m_key = _T("");
	m_encrypt_text = _T("");
	m_decrypt_text = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDESDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDESDlg)
	DDX_Text(pDX, IDC_EDIT1, m_plain);
	DDX_Text(pDX, IDC_EDIT2, m_key);
	DDX_Text(pDX, IDC_EDIT3, m_decrypt_text);
	DDX_Text(pDX, IDC_EDIT4, m_encrypt_text);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDESDlg, CDialog)
	//{{AFX_MSG_MAP(CDESDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEAN, OnClean)
	ON_BN_CLICKED(IDC_DECRYPT, OnDecrypt)
	ON_BN_CLICKED(IDC_ENCRYPT, OnEncrypt)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDESDlg message handlers

BOOL CDESDlg::OnInitDialog()
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

void CDESDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDESDlg::OnPaint() 
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
HCURSOR CDESDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDESDlg::OnClean() 
{
	// TODO: Add your control notification handler code here

    //补充其它代码
	SetDlgItemText(IDC_EDIT1, NULL);
	SetDlgItemText(IDC_EDIT2, NULL);
	SetDlgItemText(IDC_EDIT3, NULL);
	SetDlgItemText(IDC_EDIT4, NULL);
	memset(encrypt_text,0,256); 

}


void CDESDlg::OnEncrypt() 
{
	// TODO: Add your control notification handler code here
    char plain[256], key[8];

	memset(plain, 0, sizeof(plain));
   
	UpdateData();
    strcpy(plain,m_plain);
	strcpy(key,m_key);

	if (!plain[0]) {
	    MessageBox("明文为空，请输入明文");
		return;
    }

	if (!key[0]) {
	    MessageBox("密钥为空，请输入密钥");
		return;
    }
	//memset(encrypt_text,0,sizeof(encrypt_text));
	
	//进行DES加密
	char *buff;
	buff = plain;
	DES_OneAct(encrypt_text, plain,strlen(plain) , key, strlen(key), ENCRYPT);

	memcpy(encrypt_text, ToHexString(encrypt_text),strlen(ToHexString(encrypt_text)));
	m_encrypt_text=encrypt_text;	
	
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_encrypt_text);

    GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);


}


//DES解密响应
void CDESDlg::OnDecrypt() 
{
	// TODO: Add your control notification handler code here
	char key[8],decrypt_text[256],encrypt_text1[256];
    int i;
	char *buff;
	memset(decrypt_text, 0, sizeof(decrypt_text));
	memset(key, 0, sizeof(key));
	
	UpdateData();

	strcpy(key,m_key);
	strcpy(encrypt_text1,m_encrypt_text);

  	//进行DES解密
	memcpy(encrypt_text1, FromHexString(encrypt_text1), strlen(FromHexString(encrypt_text1)));
	buff = encrypt_text1;
	DES_OneAct(decrypt_text, encrypt_text1, strlen(buff), key, strlen(key),DECRYPT);

	m_decrypt_text=decrypt_text;

	GetDlgItem(IDC_EDIT3)->SetWindowText(m_decrypt_text);
}



void CDESDlg::OnRadio1()	//ASCII码
{
	// TODO: Add your control notification handler code here
//flag = 1;
}

void CDESDlg::OnRadio2()	//十六进制
{
	// TODO: Add your control notification handler code here
	//flag = 0;
}