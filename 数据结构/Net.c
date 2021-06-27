#include "Net.h"


//32位unsigned int或int大小端转换
unsigned int WAP_u32(unsigned int x)
{
	return (unsigned int)(((x & 0xff000000)>>24)|((x & 0x00ff0000)>>8)|((x & 0x0000ff00)<<8)|((x & 0x000000ff)<<24));
}

//16位unsigned short或short大小端转换
unsigned short WAP_u16(unsigned short x)
{
	return (unsigned short)(((x & 0xff00)>>8)|((x & 0x00ff)<<8));
}

//DOUBLE大小端转换
DOUBLE dbMemeryConvert( DOUBLE  pData )
{

	DOUBLE* pNewValue;
	DOUBLE pData0 = 0;
	
	UCHAR* pValue;
	UCHAR Value[8];
	
	pValue = (UCHAR*)&pData;

	Value[0] = pValue[7];
	Value[1] = pValue[6];
	Value[2] = pValue[5];
	Value[3] = pValue[4];
	Value[4] = pValue[3];
	Value[5] = pValue[2];
	Value[6] = pValue[1];
	Value[7] = pValue[0];

	pNewValue = (DOUBLE*)Value;
	pData0 = *pNewValue;

	return pData0;
	
}

//float大小端转换
float float_swap_32( float  pData )
{

	float* pNewValue;
	float  pData0 = 0;
	
	UCHAR* pValue;
	UCHAR  Value[4];
	
	pValue = (UCHAR*)&pData;


	Value[0] = pValue[3];
	Value[1] = pValue[2];
	Value[2] = pValue[1];
	Value[3] = pValue[0];

	pNewValue = (float*)Value;
	pData0 = *pNewValue;

	return pData0;
	
}