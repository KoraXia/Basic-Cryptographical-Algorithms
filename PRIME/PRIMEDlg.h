// PRIMEDlg.h : header file
//

#if !defined(AFX_PRIMEDLG_H__CDC6D299_A56C_4F38_ADD4_B5F4396BC200__INCLUDED_)
#define AFX_PRIMEDLG_H__CDC6D299_A56C_4F38_ADD4_B5F4396BC200__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPRIMEDlg dialog

class CPRIMEDlg : public CDialog
{
// Construction
public:
	CPRIMEDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPRIMEDlg)
	enum { IDD = IDD_PRIME_DIALOG };
	CString	m_prime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPRIMEDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPRIMEDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClean();
	afx_msg void OnExam();
	afx_msg void OnExam2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern int Eratosthenes(unsigned long n);
extern long modExpFun (long a, int e, long m); 
extern int MillerRabin (unsigned long n, int no_of_smallprimes, int iterations);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIMEDLG_H__CDC6D299_A56C_4F38_ADD4_B5F4396BC200__INCLUDED_)
