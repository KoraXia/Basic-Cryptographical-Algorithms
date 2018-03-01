#include "stdafx.h"
#include "RC4.h"

////密钥安排算法部分，完成对数据表S的初始化
void RC4_Setup( struct rc4_state *s, char *key)
{

//补充代码
	char T[256];
	unsigned int i;
	int length = strlen(key);
	for ( i = 0; i < 256; i++)   //S的初始化赋值
	{
		s->m[i] = i;
	} 
	for (i = 0; i < 256; i++)   //T的初始化赋值
	{
		T[i] = key[i % length];
	}
	int j = 0;
	char tmp;
	for (i = 0; i < 256; i++)
	{
		j = (j + s->m[i] + T[i]) % 256;
		tmp = s->m[i];
		s->m[i] = s->m[j];
		s->m[j] = tmp;
	}
}

////伪随机子密钥生成，并用该子密钥加解密数据
void RC4_Crypt( struct rc4_state *s, char *data, unsigned int length )
{ 
//补充代码
	int i = 0, j = 0, t = 0;
	unsigned int n = 0;
	char tmp;
	for (n = 0; n < length; n++)
	{
		i = (i + 1) % 256;
		j = (j + s->m[i]) % 256;
		tmp = s->m[i];
		s->m[i] = s->m[j];
		s->m[j] = tmp;
		t = (s->m[i] + s->m[j]) % 256;
		data[n] = data[n] ^ s->m[t];
	}
}

//数据类型转化
char * ToHexString(char * input)   
{
   char * Result;
   unsigned int nOutSize;
   unsigned int i, r;
   int test;
   int Table[2]={+1,-1};

   nOutSize = strlen(input) * 2;

   
   Result = (char *)malloc(nOutSize+1);

   for (i = 0; i<nOutSize; i++)
   {
      r = i + Table[i%2];
	  
      test = input[i >> 1];
	  test = test >> (((i%2) % 4) << 2);
	  test = test & 0xF;
      switch(test)
      {
      case 0:
         Result[r] = '0';
         break;
      case 1:
         Result[r] = '1';
         break;
      case 2:
         Result[r] = '2';
         break;
      case 3:
         Result[r] = '3';
         break;
      case 4:
         Result[r] = '4';
         break;
      case 5:
         Result[r] = '5';
         break;
      case 6:
         Result[r] = '6';
         break;
      case 7:
         Result[r] = '7';
         break;
      case 8:
         Result[r] = '8';
         break;
      case 9:
         Result[r] = '9';
         break;
      case 10:
         Result[r] = 'A';
         break;
      case 11:
         Result[r] = 'B';
         break;
      case 12:
         Result[r] = 'C';
         break;
      case 13:
         Result[r] = 'D';
         break;
      case 14:
         Result[r] = 'E';
         break;
      case 15:
         Result[r] = 'F';
         break;
      default:
         Result[r] = '!';
         break;
      }
   }

   Result[nOutSize] = '\0';
   return Result;
 
}

char * FromHexString(char *input)
{
   char * Result;
   unsigned int i, r,size;
   unsigned int nUseLength;
   unsigned int nPlaceVal;
   int Table[2]={+1,-1};

   nUseLength = strlen(input);
   
   size = nUseLength >> 1;
   
   Result = (char *)malloc(size+1);


   for (i=0; i<nUseLength; i+=1)
   {

	  r = i + Table[i%2];
      if ((input[r] >= '0') && (input[r] <= '9'))
         nPlaceVal = input[r] - '0';
      else if ((input[r] >= 'A') && (input[r] <= 'F'))
         nPlaceVal = input[r] - 'A' + 10;
      else if ((input[r] >= 'a') && (input[r] <= 'f'))
         nPlaceVal = input[r] - 'a' + 10;
      else
         nPlaceVal = 0;

      if (!(i % 2))
         Result[i >> 1] = nPlaceVal;
      else
         Result[i >> 1] |= nPlaceVal << (((i%2) % 4) << 2);
   }
   
   Result[size] = '\0';
   
   return Result;
}



