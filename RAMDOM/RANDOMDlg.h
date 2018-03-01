// RANDOMDlg.h : header file
//

#if !defined(AFX_RANDOMDLG_H__F5F28DE2_A65A_473C_BB78_16D2E72C8097__INCLUDED_)
#define AFX_RANDOMDLG_H__F5F28DE2_A65A_473C_BB78_16D2E72C8097__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRANDOMDlg dialog

class CRANDOMDlg : public CDialog
{
// Construction
public:
	CRANDOMDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRANDOMDlg)
	enum { IDD = IDD_RANDOM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRANDOMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRANDOMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCancel1();
	afx_msg void OnCancel2();
	afx_msg void OnLCG();
	afx_msg void OnBBS();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern unsigned long randLCG(unsigned long a, unsigned long c, unsigned long m, unsigned long seedLCG);

extern unsigned long randBBS(unsigned long n, unsigned int bitcount);

//所需其它外部函数的申明和全局变量的定义
static int inputflagLCG = 0,inputflagBBS = 0;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RANDOMDLG_H__F5F28DE2_A65A_473C_BB78_16D2E72C8097__INCLUDED_)
