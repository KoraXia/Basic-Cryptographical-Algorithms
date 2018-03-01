// DES.h : main header file for the DES application
//

#if !defined(AFX_DES_H__53595FC9_68A7_4E45_82C1_DC224CEC1253__INCLUDED_)
#define AFX_DES_H__53595FC9_68A7_4E45_82C1_DC224CEC1253__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

//////////////////////////////////////////////////////////////////////////////
typedef bool    (*PSubKey)[16][48];
enum    {ENCRYPT,DECRYPT};
static bool SubKey[2][16][48];// 16圈子密钥，一重DES，只用SubKey[0]，三重DES用SubKey[0]和SubKey[1].
static char Tmp[256], deskey[8];

/////////////////////////////////////////////////////////////////////////////
// CDESApp:
// See DES.cpp for the implementation of this class
//

class CDESApp : public CWinApp
{
public:
	CDESApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDESApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDESApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DES_H__53595FC9_68A7_4E45_82C1_DC224CEC1253__INCLUDED_)
