// RANDOM.h : main header file for the RANDOM application
//

#if !defined(AFX_RANDOM_H__D2A92486_67CB_4C68_87EA_D8FC00AA5994__INCLUDED_)
#define AFX_RANDOM_H__D2A92486_67CB_4C68_87EA_D8FC00AA5994__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRANDOMApp:
// See RANDOM.cpp for the implementation of this class
//

class CRANDOMApp : public CWinApp
{
public:
	CRANDOMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRANDOMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRANDOMApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RANDOM_H__D2A92486_67CB_4C68_87EA_D8FC00AA5994__INCLUDED_)
