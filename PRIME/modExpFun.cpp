// MODDlg.cpp : modExpFun implementation file

#include "stdafx.h"
#define STATIC_NUMBER 0xfffffffffffff
//!!!注意：以下流程和参数定义为实现的参考，允许同学们按照自己的思路完成代码。

long modExpFun (long a, int e, long m)//a 基数 e指数 m模数
{
	// step1: 定义局部变量
	__int64 p;   //将p定义为一个64位整数，以便可以进行较大数的运算，而不溢出。p用于计算p = p*p mod m
	long int tmpbase, r=0;   // r为结果,tmpbase为基底变量
    int k = 0x40000000;         //k用做掩码exponent的每个二进制数字
    
	//请参考以下提示补充程序代码，完成功能
	
	// step2: 检查输入值的有效性
    // case 1 - m,a,e有负数	
	if(a<0||m<0||e<0) {
		r=-1;
		return r;
	}
    // case 2 - 模数为0,提示：输入的模数无效 
	if(m==0) {
		r=-2;
		return r;
	}
	// step3: 特殊值处理
    // case 1 - 模数为1
    if(m==1){
		r=0;
		return r;
	}
    // case 2 - 底为0，但模数不为0
    if(a==0&&m!=0){
		r=0;
		return r;
	}
    // case 3 - 指数为0，但底数不为0
	if(e==0&&a!=0){
		r=1;
		return r;
	}
	// step4: 非上述的正常情况y
	r=1;
	tmpbase=a;
	while(k!=0){
        r=(r*r)%m;
		if((e&k)!=0)
			r=(r*tmpbase)%m;
		k>>=1;
	}
	return r;
}


