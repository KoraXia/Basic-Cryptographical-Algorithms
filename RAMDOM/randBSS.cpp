#include "stdafx.h"


extern unsigned long seedBBS,x; //存放BBS的种子
	
unsigned long randBBS(unsigned long n, unsigned int bitcount)
{
    int i,b;
	b=0;
	if(seedBBS!=0){
		x=(seedBBS*seedBBS)%n;
		seedBBS=0;
	}
	for(i=1;i<=bitcount;i++){
		x=(x*x)%n;
		b=b<<1;
		b=b+x%2;
	}
	return b;  
}