#include "stdafx.h"

long *inv(long a, long m)
{

	static long gcdInvOutArr[2]={0,0};    	//gcdInvOutArr[0]存放gcd(a,m), gcdInvOutArr[1]存放乘法逆元

   //将扩展欧几里德算法的代码拷贝过来或者将inv.cpp文件拷贝到本目录。然后加入工程。

    return (long *)gcdInvOutArr;
}