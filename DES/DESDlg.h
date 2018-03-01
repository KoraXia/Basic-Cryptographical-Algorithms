// DESDlg.h : header file
//

#if !defined(AFX_DESDLG_H__65669C0F_DCF0_4723_9A90_6A2C268DADFB__INCLUDED_)
#define AFX_DESDLG_H__65669C0F_DCF0_4723_9A90_6A2C268DADFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDESDlg dialog

class CDESDlg : public CDialog
{
// Construction
public:
	CDESDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDESDlg)
	enum { IDD = IDD_DES_DIALOG };
	CString	m_plain;
	CString	m_key;
	CString	m_encrypt_text;
	CString	m_decrypt_text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDESDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDESDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClean();
	afx_msg void OnDecrypt();
	afx_msg void OnEncrypt();
	afx_msg void OnIP();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnSetKey();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern void DES_OneAct(char *Out, char *In, long datalen, const char *Key, int keylen, bool Type);
extern void DES_TriAct(char *Out, char *In, long datalen, const char *Key1, int keylen1, const char *Key2, int keylen2,bool Type);
extern char * ToHexString(char * input);
extern char * FromHexString(char *input);
//int flag;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESDLG_H__65669C0F_DCF0_4723_9A90_6A2C268DADFB__INCLUDED_)
