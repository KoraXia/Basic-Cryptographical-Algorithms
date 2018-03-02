// Eratosthenes implementation file

#include "stdafx.h"
#include "math.h"

int Eratosthenes(unsigned long n)
{

  long i,j;
  bool *a;    //�ɱ��������a������
  int reminder, r = 1;  //reminder�����ڴ�������ı���
  
  //step1: n������ֵ����
  if(n<2){
	  r=0;
	  return r;
  }

  // �뽫�����������
  
  a = new bool [n+1];

  for (i = 2; i <= n; i++)  
	   a[i] = true; 

  for (i = 2; i <= sqrt(n); i++)  {
	  for(j=2*i;j<=n;j+=i){
		  a[j]=false;
	  }
       //  �뽫�������������������ɸ��

  }

  //�뽫���´��벹������
  for(i=2;i<=sqrt(n);i++){
	  if(a[i]==true&&(n%i)==0)
		  r=0;
  }
  
  delete a;   //�ͷ�����a�Ŀռ�
  return r;
}