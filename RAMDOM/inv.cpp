#include "stdafx.h"

long *inv(long a, long m)
{

	static long gcdInvOutArr[2]={0,0};    	//gcdInvOutArr[0]���gcd(a,m), gcdInvOutArr[1]��ų˷���Ԫ

   //����չŷ������㷨�Ĵ��뿽���������߽�inv.cpp�ļ���������Ŀ¼��Ȼ����빤�̡�

    return (long *)gcdInvOutArr;
}