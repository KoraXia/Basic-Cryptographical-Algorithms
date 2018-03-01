#include "stdafx.h"

extern unsigned long seedLCG; //存放LCG的种子

unsigned long randLCG(unsigned long a, unsigned long c, unsigned long m, unsigned long seedLCG)
{
	seedLCG=(a*seedLCG+c)%m;
	return seedLCG;
}

