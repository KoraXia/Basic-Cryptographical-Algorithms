/*
 *****************************************************************************
 *
 *  SHA1ACT.c
 *
 *
 *  Description:
 *      This file implements the Secure Hashing Standard as defined
 *      in FIPS PUB 180-1 published April 17, 1995.
 *
 *      The Secure Hashing Standard, which uses the Secure Hashing
 *      Algorithm (SHA), produces a 160-bit message digest for a
 *      given data stream.  In theory, it is highly improbable that
 *      two messages will produce the same message digest.  Therefore,
 *      this algorithm can serve as a means of providing a "fingerprint"
 *      for a message.
 *
 *  Portability Issues:
 *      SHA-1 is defined in terms of 32-bit "words".  This code was
 *      written with the expectation that the processor has at least
 *      a 32-bit machine word size.  If the machine word size is larger,
 *      the code should still function properly.  One caveat to that
 *      is that the input functions taking characters and character
 *      arrays assume that only 8 bits of information are stored in each
 *      character.
 *
 *  Caveats:
 *      SHA-1 is designed to work with messages less than 2^64 bits
 *      long. Although SHA-1 allows a message digest to be generated for
 *      messages of any number of bits less than 2^64, this
 *      implementation only works with messages with a length that is a
 *      multiple of the size of an 8-bit character.
 *
 *****************************************************************************
 */

#include "stdafx.h"

//根据资料，完成此文件的内容
char * FromHexString(char *input)
{
	char * Result;
	unsigned int i, r, size;
	unsigned int nUseLength;
	unsigned int nPlaceVal;
	int Table[2] = { +1,-1 };

	nUseLength = strlen(input);

	size = nUseLength >> 1;

	Result = (char *)malloc(size + 1);


	for (i = 0; i<nUseLength; i += 1)
	{

		r = i + Table[i % 2];
		if ((input[r] >= '0') && (input[r] <= '9'))
			nPlaceVal = input[r] - '0';
		else if ((input[r] >= 'A') && (input[r] <= 'F'))
			nPlaceVal = input[r] - 'A' + 10;
		else if ((input[r] >= 'a') && (input[r] <= 'f'))
			nPlaceVal = input[r] - 'a' + 10;
		else
			nPlaceVal = 0;

		if (!(i % 2))
			Result[i >> 1] = nPlaceVal;
		else
			Result[i >> 1] |= nPlaceVal << (((i % 2) % 4) << 2);
	}

	Result[size] = '\0';

	return Result;
}


char * ToHexString(char * input)
{
	char * Result;
	unsigned int nOutSize;
	unsigned int i, r;
	int test;
	int Table[2] = { +1,-1 };

	nOutSize = strlen(input) * 2;


	Result = (char *)malloc(nOutSize + 1);

	for (i = 0; i<nOutSize; i++)
	{
		r = i + Table[i % 2];

		test = input[i >> 1];
		test = test >> (((i % 2) % 4) << 2);
		test = test & 0xF;
		switch (test)
		{
		case 0:
			Result[r] = '0';
			break;
		case 1:
			Result[r] = '1';
			break;
		case 2:
			Result[r] = '2';
			break;
		case 3:
			Result[r] = '3';
			break;
		case 4:
			Result[r] = '4';
			break;
		case 5:
			Result[r] = '5';
			break;
		case 6:
			Result[r] = '6';
			break;
		case 7:
			Result[r] = '7';
			break;
		case 8:
			Result[r] = '8';
			break;
		case 9:
			Result[r] = '9';
			break;
		case 10:
			Result[r] = 'A';
			break;
		case 11:
			Result[r] = 'B';
			break;
		case 12:
			Result[r] = 'C';
			break;
		case 13:
			Result[r] = 'D';
			break;
		case 14:
			Result[r] = 'E';
			break;
		case 15:
			Result[r] = 'F';
			break;
		default:
			Result[r] = '!';
			break;
		}
	}

	Result[nOutSize] = '\0';
	return Result;

}