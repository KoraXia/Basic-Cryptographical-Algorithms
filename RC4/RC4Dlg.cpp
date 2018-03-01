// RC4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "RC4.h"
#include "RC4Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static char buffer[256]; //用于保存密文，与明文大小一致，最大设置为1024个字节

extern void RC4_Setup( struct rc4_state *s, char *key);
extern void RC4_Crypt( struct rc4_state *s, char *data, unsigned int length );
extern char * ToHexString(char * input) ;
extern char * FromHexString(char *input) ;
int choose;
//struct rc4_state s;
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
// CRC4Dlg dialog

CRC4Dlg::CRC4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRC4Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRC4Dlg)
	m_plain = _T("");
	m_key = _T("");
	m_encrypt_text = _T("");
	m_decrypt_text = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRC4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRC4Dlg)
	DDX_Text(pDX, IDC_PLAIN, m_plain);
	DDX_Text(pDX, IDC_KEY, m_key);
	DDX_Text(pDX, IDC_EDIT3, m_encrypt_text);
	DDX_Text(pDX, IDC_EDIT4, m_decrypt_text);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRC4Dlg, CDialog)
	//{{AFX_MSG_MAP(CRC4Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ENCRYPT, OnEncrypt)
	ON_BN_CLICKED(IDC_DECRYPT, OnDecrypt)
	ON_BN_CLICKED(IDC_CLEAN, OnClean)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRC4Dlg message handlers

BOOL CRC4Dlg::OnInitDialog()
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

void CRC4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRC4Dlg::OnPaint() 
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
HCURSOR CRC4Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRC4Dlg::OnEncrypt() 
{
	// TODO: Add your control notification handler code here
	struct rc4_state s;
	char data[256],key[256];
    int i;
	char *inbuf;
	for (i=0; i<256; i++) 
	{
       data[i] =0;
	}

	UpdateData();	//将在界面控件上输入的数据，更新到与控件相关连的变量中。经过该调用，m_plain和m_key才获得有数据。
    strcpy(data,m_plain);
	strcpy(key,m_key);

	inbuf=data;
	memcpy(buffer,data,strlen(inbuf));//buffer用于保存密文


    //补充代码
	/////////////////////////////////////////////
	if(choose==1)
	{
		RC4_Setup(&s,key);
		RC4_Crypt(&s,inbuf,strlen(inbuf));
		inbuf=ToHexString(inbuf);
		memcpy(buffer,inbuf,strlen(inbuf));
	}
	else
	{
		int x=strlen(data);
		if (strlen(data) % 2 == 1) { x += 1; }
		RC4_Setup(&s,key);
		RC4_Crypt(&s,data,x);
		memcpy(buffer,data,x);
	}
	
	/////////////////////////////////////////////
	m_encrypt_text = buffer;	
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_encrypt_text);
	for (i=0; i<256; i++) 
	{
       data[i] =0;
	}

}

void CRC4Dlg::OnDecrypt() 
{
	// TODO: Add your control notification handler code here
	struct rc4_state s;
	char data[256],key[256];
	int i=0;

	char *outbuf;

	UpdateData();
	strcpy(key,m_key);
    strcpy(data,m_encrypt_text);
	outbuf = data;

    //补充代码
	/////////////////////////////////////////////////////////////////////
	if(choose==1)
	{
		outbuf=FromHexString(outbuf);
		RC4_Setup(&s,key);
		RC4_Crypt(&s,outbuf,strlen(outbuf));
		memcpy(buffer,outbuf,strlen(outbuf));
		buffer[strlen(outbuf)]='\0';
	}
	else
	{
		RC4_Setup(&s,key);
		RC4_Crypt(&s,outbuf,strlen(outbuf));
		memcpy(buffer,outbuf,strlen(outbuf));
	}
	/////////////////////////////////////////////////////////////////////
	m_decrypt_text = buffer;	
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_decrypt_text);
	for (i=0; i<256; i++) 
	{
       data[i] =0;
	}

}

void CRC4Dlg::OnClean() 
{
	// TODO: Add your control notification handler code here
    //补充代码
	SetDlgItemText(IDC_PLAIN, NULL);
	SetDlgItemText(IDC_KEY, NULL);
	SetDlgItemText(IDC_EDIT3, NULL);
	SetDlgItemText(IDC_EDIT4, NULL);
}



void CRC4Dlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	choose=0;
	
}

void CRC4Dlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	choose=1;
	
}
