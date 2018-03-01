// RC4Dlg.h : header file
//

#if !defined(AFX_RC4DLG_H__C31F87BD_F435_4528_89A8_A464F63A54A5__INCLUDED_)
#define AFX_RC4DLG_H__C31F87BD_F435_4528_89A8_A464F63A54A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRC4Dlg dialog

class CRC4Dlg : public CDialog
{
// Construction
public:
	CRC4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRC4Dlg)
	enum { IDD = IDD_RC4_DIALOG };
	CString	m_plain;
	CString	m_key;
	CString	m_encrypt_text;
	CString	m_decrypt_text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRC4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRC4Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEncrypt();
	afx_msg void OnDecrypt();
	afx_msg void OnClean();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RC4DLG_H__C31F87BD_F435_4528_89A8_A464F63A54A5__INCLUDED_)
