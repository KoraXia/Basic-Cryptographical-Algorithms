#include "stdafx.h"

long *inv(long a, long m)
{
	long remainder,u,g,q,v1,t3,t1;  //补充所需的局部变量
	static long gcdInvOutArr[2]={0,0};    	//gcdInvOutArr[0]存放gcd(a,m), gcdInvOutArr[1]存放乘法逆元

    gcdInvOutArr[0] = 0;
    gcdInvOutArr[1] = 0;

    // case 1 - 运算对象做零检查，存在零则无逆元，但存在最大公约数
    if(a==0||m==0){
		gcdInvOutArr[1] = 0;
		gcdInvOutArr[0] = 0;
		return (long *)gcdInvOutArr;
	}

    // case 2 - a 和 m 均非零的情况 
 

    u = 1;
	g = a;
	v1 = 0;
	remainder = m;

    //通过带余除法逐次计算出最大公约数remainder和逆元inverse
    do {
		q = g/remainder;
		t3 = g%remainder;
		if(remainder != 0){  //判断余数是否为0
			t1 = (u - q*v1) % m;
			u = v1;
			g = remainder;
			v1 = t1;
			remainder = t3;
		}
		//......
    } while (remainder > 0);          //如果余数大于0继续循环，否则退出循环
    gcdInvOutArr[0] = g;
     //gcdInvOutArr[0] = 前面定义的、用于存放最大公约数的局部变量;
    
	u = 1;
	g = a;
	v1 = 0;
	remainder = m;

    do {
		q = g/remainder;
		t3 = g%remainder;
		if(t3 != 0){  //判断余数是否为0
			t1 = (u - q*v1 ) % m;
			u = v1;
			g = remainder;
			v1 = t1;
			remainder = t3;
		}
		//......
    } while (t3 != 0);
	gcdInvOutArr[0] = remainder;

	if (gcdInvOutArr[0] == 1)  {    //如果最大公约数为1
        if(v1>0)
			gcdInvOutArr[1] = v1;
		else 
			gcdInvOutArr[1] = m + v1;
		// ......
    }
    else                             //否则，无逆元，赋于0
      gcdInvOutArr[1] = 0;

   return (long *)gcdInvOutArr;
}