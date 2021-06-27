/*************************************************************************
>> File Name: C_FloatDouble_Binaryprint.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com

>> Created Time: 2021/6/6 21:53:44

>> 此程序的功能是：将float、double、int、char、unsigned int、unsigned char 以二进制格式输出
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<limits.h>
#include<math.h>
#include<string.h>
#include<inttypes.h>
#include<stddef.h>
#include<locale.h>
#include<time.h>
#include<complex.h>

typedef char				s8;
typedef short				s16;
typedef int				s32;
typedef long long			s64;
typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned int		u32;
typedef volatile unsigned int	vu32;
typedef unsigned long long	u64;


//字符串转十六进制
void StrToHex(char *pbDest, char *pbSrc, int nLen)
{
    char h1,h2;
    char s1,s2;
    int i;

    for(int i=0; i<nLen/2; ++i)
    {
        h1 = pbSrc[2*i];
        h2 = pbSrc[2*i+1];

        s1 = toupper(h1) - 0x30;
        if(s1>9)
        {
            s1 -= 7;
        }
        s2 = toupper(h2) - 0x30;
        if(s2>9)
        {
            s2 -= 7;
        }
        pbDest[i] = s1*16 + s2;
    }
}


//十六进制转字符串
void HexToStr(char *pszDest, char *pbSrc, int nlen)
{
    char ddl, ddh;
    for(int i = 0; i < nlen; ++i)
    {
        ddh = 48 + pbSrc[i]/16;
        ddl = 48 + pbSrc[i]%16;
        if(ddh > 57)
        {
            ddh = ddh + 7;
        }
        if(ddl > 57)
        {
            ddl = ddl + 7;
        }
        pszDest[i*2] = ddh;
        pszDest[i*2+1] = ddl;
    }
    pszDest[nlen*2] = '\0';
}


//字符串转十进制,如果带负号
int my_atoi(const char * str)
{
    int value = 0;
    int flag  = 1; //判断符号
    while( *str == ' ')//跳过字符串前面的空格
    {
        str++;
    }
    if(*str == '-')
    {
        flag = 0;
        str++;
    }
    else if(*str == '+')
    {
        flag = 1;
        str++;
    }
    else if(*str >= '9' || *str <='0')
    {
        return 0;
    }
    while(*str != '\0' && *str <= '9' && *str >= '0')
    {
        value = value*10 + *str-'0';//将数字字符串转化为对应的整数形式
        str++;
    }

    if(flag == 0)
    {
        value = -value;
    }

    return value;
}

//字符串转十进制,如果不带负号
void StrtoDec(uint32_t *pbDest, char *pbSrc, int nLen)
{
    int i;
    int tmp = 0;
    if(nLen > 10)
        *pbDest = 0;
    for(i = nLen-1; i>=0; i--)
    {
        *pbDest += tmp*(*(pbSrc+i) - '0');
        tmp = tmp*10;
    }
}


//字符串转十进制,可以是浮点数
//m^n函数
//返回值：m^n次方
u32 NMEA_pow(u8 m, u8 n)
{
    u32 result = 1;
    while(n--)
    {
        result *= m;
    }
    return result;
}

/*字符串转十进制,可以是浮点数
字符串转换为数字，以','或'*'结束
buf:数字存储区
dx: 小数点位数，返回给调用函数
返回值:转换后的数值
*/
int NMEA_Str2num(u8 *buf, u8 *dx)
{
    u8 *p = buf;
    u32 ires = 0, fres = 0;
    u8 ilen = 0,flen = 0, i;
    u8 mask = 0;
    int res;


    while(1)
    {
        if(*p == '-')//是负数
        {
            mask|=0x02;
            p++;
        }
        if(*p == ',' || *p == '*')//遇到结束符
        {
            break;
        }
        if(*p == '.')//遇到小数了
        {
            mask |= 0x01;
            p++;
        }
        else if(*p>'9'||(*p<'0'))//有非法字符
        {
            ilen = 0;
            flen = 0;
            break;
        }
        if(mask&0x01)
        {
            flen++;
        }
        else
        {
            ilen++;
        }
        p++;
    }

    if(mask&0x02)
    {
        buf++;
    }
    for(i = 0; i<ilen; ++i)//得到整数部分数据
    {
        ires += NMEA_pow(10, ilen-1-i)*(buf[i]-'0');
    }
    if(flen>5)//最多取5位参数
    {
        flen = 5;
    }
    *dx = flen;//小数点位数
    for(i = 0; i< flen; i++)
    {
        fres = NMEA_pow(10, flen-1-i)*(buf[ilen+1+i]-'0');
    }
    res = ires*NMEA_pow(10,flen)+fres;
    if(mask&0x02)
    {
        res = -res;
    }
    return res;
}

//十进制转字符串
u16 DecToStr(u8 *pSrc, u16 SrcLen, u8 *pObj)
{
    u16 i = 0;
    for(i=0; i<SrcLen; ++i)
    {
        sprintf((char *)(pObj + i*2), "%02d", *(pSrc+i));
    }
    *(pObj+i*2) = '\0';
    return (i*2);
}



int main(int argc, char *argv[])
{

    char S[10] = "1234";
    int result = 0;

    result = my_atoi(S);
    printf("result = %d\n",result);

    return 0;

}
