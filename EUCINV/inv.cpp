#include "stdafx.h"

long *inv(long a, long m)
{
	long remainder,u,g,q,v1,t3,t1;  //��������ľֲ�����
	static long gcdInvOutArr[2]={0,0};    	//gcdInvOutArr[0]���gcd(a,m), gcdInvOutArr[1]��ų˷���Ԫ

    gcdInvOutArr[0] = 0;
    gcdInvOutArr[1] = 0;

    // case 1 - ������������飬������������Ԫ�����������Լ��
    if(a==0||m==0){
		gcdInvOutArr[1] = 0;
		gcdInvOutArr[0] = 0;
		return (long *)gcdInvOutArr;
	}

    // case 2 - a �� m ���������� 
 

    u = 1;
	g = a;
	v1 = 0;
	remainder = m;

    //ͨ�����������μ�������Լ��remainder����Ԫinverse
    do {
		q = g/remainder;
		t3 = g%remainder;
		if(remainder != 0){  //�ж������Ƿ�Ϊ0
			t1 = (u - q*v1) % m;
			u = v1;
			g = remainder;
			v1 = t1;
			remainder = t3;
		}
		//......
    } while (remainder > 0);          //�����������0����ѭ���������˳�ѭ��
    gcdInvOutArr[0] = g;
     //gcdInvOutArr[0] = ǰ�涨��ġ����ڴ�����Լ���ľֲ�����;
    
	u = 1;
	g = a;
	v1 = 0;
	remainder = m;

    do {
		q = g/remainder;
		t3 = g%remainder;
		if(t3 != 0){  //�ж������Ƿ�Ϊ0
			t1 = (u - q*v1 ) % m;
			u = v1;
			g = remainder;
			v1 = t1;
			remainder = t3;
		}
		//......
    } while (t3 != 0);
	gcdInvOutArr[0] = remainder;

	if (gcdInvOutArr[0] == 1)  {    //������Լ��Ϊ1
        if(v1>0)
			gcdInvOutArr[1] = v1;
		else 
			gcdInvOutArr[1] = m + v1;
		// ......
    }
    else                             //��������Ԫ������0
      gcdInvOutArr[1] = 0;

   return (long *)gcdInvOutArr;
}