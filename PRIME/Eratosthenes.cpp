// Eratosthenes implementation file

#include "stdafx.h"
#include "math.h"

int Eratosthenes(unsigned long n)
{

  long i,j;
  bool *a;    //可变数组变量a的申明
  int reminder, r = 1;  //reminder是用于存放余数的变量
  
  //step1: n的特殊值处理
  if(n<2){
	  r=0;
	  return r;
  }

  // 请将补充代码完整
  
  a = new bool [n+1];

  for (i = 2; i <= n; i++)  
	   a[i] = true; 

  for (i = 2; i <= sqrt(n); i++)  {
	  for(j=2*i;j<=n;j+=i){
		  a[j]=false;
	  }
       //  请将补充代码完整，将合数筛除

  }

  //请将余下代码补充完整
  for(i=2;i<=sqrt(n);i++){
	  if(a[i]==true&&(n%i)==0)
		  r=0;
  }
  
  delete a;   //释放数组a的空间
  return r;
}