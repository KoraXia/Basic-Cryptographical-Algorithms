#include "stdafx.h"

extern unsigned long seedLCG; //���LCG������

unsigned long randLCG(unsigned long a, unsigned long c, unsigned long m, unsigned long seedLCG)
{
	seedLCG=(a*seedLCG+c)%m;
	return seedLCG;
}

