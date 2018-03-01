// SHA1Dlg.h : header file
//

#if !defined(AFX_SHA1DLG_H__083ED0B6_E167_4FA8_A45D_AFF90186EB0B__INCLUDED_)
#define AFX_SHA1DLG_H__083ED0B6_E167_4FA8_A45D_AFF90186EB0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSHA1Dlg dialog

class CSHA1Dlg : public CDialog
{
// Construction
public:
	CSHA1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSHA1Dlg)
	enum { IDD = IDD_SHA1_DIALOG };
	CString	m_plain;
	CString	m_abstract;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSHA1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSHA1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHash();
	afx_msg void OnClean();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
};

//补充必要的内容

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHA1DLG_H__083ED0B6_E167_4FA8_A45D_AFF90186EB0B__INCLUDED_)
