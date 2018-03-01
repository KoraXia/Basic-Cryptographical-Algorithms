// RSADlg.h : header file
//

#if !defined(AFX_RSADLG_H__4682A326_77F2_417E_A110_A154607834EA__INCLUDED_)
#define AFX_RSADLG_H__4682A326_77F2_417E_A110_A154607834EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "bignum.h"

/////////////////////////////////////////////////////////////////////////////
// CRSADlg dialog

class CRSADlg : public CDialog
{
// Construction
public:
	CRSADlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRSADlg)
	enum { IDD = IDD_RSA_DIALOG };
	CString	m_plain;
	CString	m_pubn;
	CString	m_pube;
	CString	m_prid;
	CString	m_encrypt;
	CString	m_decrypt;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSADlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRSADlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClean();
	afx_msg void OnDecrypt();
	afx_msg void OnEncrypt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern void RSAEncrypt(char *publickey,char *publicmod, char *output, unsigned int *outputlen, char *input, unsigned int inputlen);
extern void RSADecrypt(char *output, unsigned int *outputlen, char *input, unsigned int inputlen);
extern void GenerateKeys(CBigNumString &PublicMod, CBigNumString &PublicKey, CBigNumString &PrivateKey, unsigned short nBytes);

extern CBigNumString strMod, strPubKey, strPriKey; // 初始化大数字符变量

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSADLG_H__4682A326_77F2_417E_A110_A154607834EA__INCLUDED_)
