// SHA1.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SHA1.h"
#include "SHA1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSHA1App

BEGIN_MESSAGE_MAP(CSHA1App, CWinApp)
	//{{AFX_MSG_MAP(CSHA1App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSHA1App construction

CSHA1App::CSHA1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSHA1App object

CSHA1App theApp;

/////////////////////////////////////////////////////////////////////////////
// CSHA1App initialization

BOOL CSHA1App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CSHA1Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}





/* Define the circular shift macro */
#define SHA1CircularShift(bits,word) \
 ((((word) << (bits)) & 0xFFFFFFFF) | ((word) >> (32-(bits))))

/* Function prototypes */
void SHA1ProcessMessageBlock(SHA1Context *);
void SHA1PadMessage(SHA1Context *);


void SHA1Reset(SHA1Context *context)
{
	context->Length_Low = 0;
	context->Length_High = 0;
	context->Message_Block_Index = 0;

	/*提示：教材上的寄存器A-D的内容已经按照最高有效字节存储在低地址字节位置的要求安排好了，所以可以直接拿来使用。*/
	context->Message_Digest[0] = 0x67452301;
	context->Message_Digest[1] = 0xEFCDAB89;
	context->Message_Digest[2] = 0x98BADCFE;
	context->Message_Digest[3] = 0x10325476;
	context->Message_Digest[4] = 0xC3D2E1F0;

	context->Computed = 0;
	context->Corrupted = 0;
}

/* This function will return the 160-bit message digest into the Message_Digest array within the SHA1Context provided */
int SHA1Result(SHA1Context *context)
{

	if (context->Corrupted)
	{
		return 0;
	}

	if (!context->Computed)
	{
		SHA1PadMessage(context);
		context->Computed = 1;
	}

	return 1;
}


void SHA1Input(SHA1Context  *context, const char *message_array, unsigned length)
{
	if (!length)
	{
		return;
	}

	if (context->Computed || context->Corrupted)
	{
		context->Corrupted = 1;
		return;
	}

	while (length-- && !context->Corrupted)
	{
		context->Message_Block[context->Message_Block_Index++] =
			(*message_array & 0xFF);

		context->Length_Low += 8;
		/* Force it to 32 bits */
		context->Length_Low &= 0xFFFFFFFF;
		if (context->Length_Low == 0)
		{
			context->Length_High++;
			/* Force it to 32 bits */
			context->Length_High &= 0xFFFFFFFF;
			if (context->Length_High == 0)
			{
				/* Message is too long */
				context->Corrupted = 1;
			}
		}

		if (context->Message_Block_Index == 64)
		{
			SHA1ProcessMessageBlock(context);  /*注意经过此函数调用后，context->Message_Block_Index 的变化。*/
		}

		message_array++;
	}
}

/*This function will process the next 512 bits of the message stored in the Message_Block array. */
void SHA1ProcessMessageBlock(SHA1Context *context)
{
	const unsigned K[] =            /* Constants defined in SHA-1   */
	{
		0x5A827999,
		0x6ED9EBA1,
		0x8F1BBCDC,
		0xCA62C1D6
	};
	int         t;                  /* Loop counter                 */
	unsigned    temp;               /* Temporary word value         */
	unsigned    W[80];              /* Word sequence                */
	unsigned    A, B, C, D, E;      /* Word buffers                 */

									/*
									*  Initialize the first 16 words in the array W
									*/
	for (t = 0; t < 16; t++)
	{
		W[t] = ((unsigned)context->Message_Block[t * 4]) << 24;
		W[t] |= ((unsigned)context->Message_Block[t * 4 + 1]) << 16;
		W[t] |= ((unsigned)context->Message_Block[t * 4 + 2]) << 8;
		W[t] |= ((unsigned)context->Message_Block[t * 4 + 3]);
	}

	for (t = 16; t < 80; t++)
	{
		W[t] = SHA1CircularShift(1, W[t - 3] ^ W[t - 8] ^ W[t - 14] ^ W[t - 16]);
	}

	A = context->Message_Digest[0];
	B = context->Message_Digest[1];
	C = context->Message_Digest[2];
	D = context->Message_Digest[3];
	E = context->Message_Digest[4];

	for (t = 0; t < 20; t++)
	{
		temp = SHA1CircularShift(5, A) +
			((B & C) | ((~B) & D)) + E + W[t] + K[0];
		temp &= 0xFFFFFFFF;
		E = D;
		D = C;
		C = SHA1CircularShift(30, B);
		B = A;
		A = temp;
	}

	for (t = 20; t < 40; t++)
	{
		temp = SHA1CircularShift(5, A) + (B ^ C ^ D) + E + W[t] + K[1];
		temp &= 0xFFFFFFFF;
		E = D;
		D = C;
		C = SHA1CircularShift(30, B);
		B = A;
		A = temp;
	}

	for (t = 40; t < 60; t++)
	{
		temp = SHA1CircularShift(5, A) +
			((B & C) | (B & D) | (C & D)) + E + W[t] + K[2];
		temp &= 0xFFFFFFFF;
		E = D;
		D = C;
		C = SHA1CircularShift(30, B);
		B = A;
		A = temp;
	}

	for (t = 60; t < 80; t++)
	{
		temp = SHA1CircularShift(5, A) + (B ^ C ^ D) + E + W[t] + K[3];
		temp &= 0xFFFFFFFF;
		E = D;
		D = C;
		C = SHA1CircularShift(30, B);
		B = A;
		A = temp;
	}

	context->Message_Digest[0] =
		(context->Message_Digest[0] + A) & 0xFFFFFFFF;
	context->Message_Digest[1] =
		(context->Message_Digest[1] + B) & 0xFFFFFFFF;
	context->Message_Digest[2] =
		(context->Message_Digest[2] + C) & 0xFFFFFFFF;
	context->Message_Digest[3] =
		(context->Message_Digest[3] + D) & 0xFFFFFFFF;
	context->Message_Digest[4] =
		(context->Message_Digest[4] + E) & 0xFFFFFFFF;

	context->Message_Block_Index = 0;  /*提示：注意此函数的最后这句。在该函数被调用的地方，注意此语句带来的变化。*/
}

/*
*  SHA1PadMessage
*
*  Description:
*      According to the standard, the message must be padded to an even
*      512 bits.  The first padding bit must be a '1'.  The last 64
*      bits represent the length of the original message.  All bits in
*      between should be 0.  This function will pad the message
*      according to those rules by filling the Message_Block array
*      accordingly.  It will also call SHA1ProcessMessageBlock()
*      appropriately.  When it returns, it can be assumed that the
*      message digest has been computed.
*
*  Parameters:
*      context: [in/out] The context to pad
*/
void SHA1PadMessage(SHA1Context *context)
{
	/*
	*  Check to see if the current message block is too small to hold
	*  the initial padding bits and length.  If so, we will pad the
	*  block, process it, and then continue padding into a second
	*  block.
	*  
	*/
	if (context->Message_Block_Index > 55)   /* 提示：剩余的长度不够64比特，需要填充1和若干0，使得消息长度满足k*512+448*/
	{
		context->Message_Block[context->Message_Block_Index++] = 0x80;
		while (context->Message_Block_Index < 64)
		{
			context->Message_Block[context->Message_Block_Index++] = 0;
		}

		SHA1ProcessMessageBlock(context);  /*提示：对于第一个512比特进行SHA1处理。注意经过此函数调用后，context->Message_Block_Index 变化为多少。*/

		while (context->Message_Block_Index < 56)
		{
			context->Message_Block[context->Message_Block_Index++] = 0; /*提示：context->Message_Block_Index++，先使用context->Message_Block_Index ，再增加1*/
		}
	}
	else
	{
		context->Message_Block[context->Message_Block_Index++] = 0x80;
		while (context->Message_Block_Index < 56)
		{
			context->Message_Block[context->Message_Block_Index++] = 0;
		}
	}

	/*
	*  Store the message length 8*8bits = 64bits
	*/
	context->Message_Block[56] = (context->Length_High >> 24) & 0xFF;
	context->Message_Block[57] = (context->Length_High >> 16) & 0xFF;
	context->Message_Block[58] = (context->Length_High >> 8) & 0xFF;
	context->Message_Block[59] = (context->Length_High) & 0xFF;
	context->Message_Block[60] = (context->Length_Low >> 24) & 0xFF;
	context->Message_Block[61] = (context->Length_Low >> 16) & 0xFF;
	context->Message_Block[62] = (context->Length_Low >> 8) & 0xFF;
	context->Message_Block[63] = (context->Length_Low) & 0xFF;

	SHA1ProcessMessageBlock(context);
}

