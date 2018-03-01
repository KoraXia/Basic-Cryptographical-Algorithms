// MODDlg.cpp : modExpFun implementation file

#include "stdafx.h"
#define STATIC_NUMBER 0xfffffffffffff
//!!!ע�⣺�������̺Ͳ�������Ϊʵ�ֵĲο�������ͬѧ�ǰ����Լ���˼·��ɴ��롣

long modExpFun (long a, int e, long m)//a ���� eָ�� mģ��
{
	// step1: ����ֲ�����
	__int64 p;   //��p����Ϊһ��64λ�������Ա���Խ��нϴ��������㣬���������p���ڼ���p = p*p mod m
	long int tmpbase, r=0;   // rΪ���,tmpbaseΪ���ױ���
    int k = 0x40000000;         //k��������exponent��ÿ������������
    
	//��ο�������ʾ���������룬��ɹ���
	
	// step2: �������ֵ����Ч��
    // case 1 - m,a,e�и���	
	if(a<0||m<0||e<0) {
		r=-1;
		return r;
	}
    // case 2 - ģ��Ϊ0,��ʾ�������ģ����Ч 
	if(m==0) {
		r=-2;
		return r;
	}
	// step3: ����ֵ����
    // case 1 - ģ��Ϊ1
    if(m==1){
		r=0;
		return r;
	}
    // case 2 - ��Ϊ0����ģ����Ϊ0
    if(a==0&&m!=0){
		r=0;
		return r;
	}
    // case 3 - ָ��Ϊ0����������Ϊ0
	if(e==0&&a!=0){
		r=1;
		return r;
	}
	// step4: ���������������y
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


