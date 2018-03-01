// PRIME.h : main header file for the PRIME application
//

#if !defined(AFX_PRIME_H__D95DD011_3998_402E_84C2_7151BD640472__INCLUDED_)
#define AFX_PRIME_H__D95DD011_3998_402E_84C2_7151BD640472__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPRIMEApp:
// See PRIME.cpp for the implementation of this class
//

class CPRIMEApp : public CWinApp
{
public:
	CPRIMEApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPRIMEApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPRIMEApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIME_H__D95DD011_3998_402E_84C2_7151BD640472__INCLUDED_)
