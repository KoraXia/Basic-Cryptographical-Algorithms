// RC4.h : main header file for the RC4 application
//

#if !defined(AFX_RC4_H__D5691DD5_B9C7_4F7E_B44A_468E0C9B6AC4__INCLUDED_)
#define AFX_RC4_H__D5691DD5_B9C7_4F7E_B44A_468E0C9B6AC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
struct rc4_state
{
	unsigned char m[256];     //数组m用于存放表S的内容
};

/////////////////////////////////////////////////////////////////////////////
// CRC4App:
// See RC4.cpp for the implementation of this class
//

class CRC4App : public CWinApp
{
public:
	CRC4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRC4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRC4App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RC4_H__D5691DD5_B9C7_4F7E_B44A_468E0C9B6AC4__INCLUDED_)


