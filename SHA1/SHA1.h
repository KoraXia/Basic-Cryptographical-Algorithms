// SHA1.h : main header file for the SHA1 application
//

#if !defined(AFX_SHA1_H__E908F733_2F87_4863_B92D_A77ABBBB4663__INCLUDED_)
#define AFX_SHA1_H__E908F733_2F87_4863_B92D_A77ABBBB4663__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSHA1App:
// See SHA1.cpp for the implementation of this class
//

class CSHA1App : public CWinApp
{
public:
	CSHA1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSHA1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSHA1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
typedef  unsigned long  uint32_t;
typedef  unsigned char  uint8_t;

/* This structure will hold context information for the hashing operation */
typedef struct SHA1Context
{
	uint32_t Message_Digest[5];         /* Message Digest (output)          */
	uint32_t Length_Low;              /* Message length in bits           */
	uint32_t Length_High;             /* Message length in bits           */
	uint8_t Message_Block[64];    /* 512-bit message blocks      */
	int Message_Block_Index;           /* Index into message block array   */
	int Computed;                     /* Is the digest computed?          */
	int Corrupted;                     /* Is the message digest corruped?  */
} SHA1Context;

/* Function Prototypes */
void SHA1Reset(SHA1Context *);
int SHA1Result(SHA1Context *);
void SHA1Input(SHA1Context *, const char *, unsigned);









#endif // !defined(AFX_SHA1_H__E908F733_2F87_4863_B92D_A77ABBBB4663__INCLUDED_)
