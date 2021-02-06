/*************************************************************************
>> File Name: C_time.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
 
>> Created Time: 2021年02月03日 星期三 19时44分53秒
>> Last Modified : 2021年02月03日 星期三 21时00分48秒
>> 此程序的功能是：时间操作函数在实际项目开发中会经常用到，最近做项目也正好用到就正好顺便整理一下。

------------                                                                        ---------------
|  string  |                                                                        |format string|
------------                                                                        ---------------
 /\      /\                                                                          /\
/--\    /--\                                                                        /--\
 -        -                                                                       -
   -        -                                                                   -
    -         - asctime()                                                     -
     -          -                                                           -
      -           -                                                       - strftime()
       -            -                                                   -
        -             -                                               -
         -              -                                           -
          -               -                                       -
           -                -                                   -
            -                 -----------------------------------
             -                   |struct tm | (broken-down time)
      ctime() -               -----------------------------------
               -               /|\        /|\                   |
                -               |          |                    |
                 -      gmtime()|          | localtime()        | mktime()
                  -             |          |                    |
                   -            |          |                    |
                    -           |          |                    |
                     -          |          |                    |
                      -         |          |                    |
                       -        |          |                    |
                        -       |          |                    |
                         -      |          |                    |
                          -     |          |                    |
                           -    |          |                   \|/
                            -------------------------------------------------------
                            |   time_t               |             ()calendar time
                            -------------------------------------------------------
                                               /|\
                                                |
                                                |
                                                |
                                                |
                                              kernel

由上图可知：

1. 通过系统调用函数time()可以从内核获得一个类型为time_t的1个值，该值叫calendar时间，即从1970年1月1日的UTC时间从0时0分0妙算起到现在所经过的秒数。而该时间也用于纪念UNIX的诞生。
2. 函数gmtime()、localtime()可以将calendar时间转变成struct tm结构体类型变量中。通过该结构体成员可以很方便的得到当前的时间信息。我们也可以通过函数mktime将该类型结构体的变量转变成calendar时间。

struct tm{
 int tm_sec;//*秒数
 int tm_min; //*分钟
 int tm_hour;//*小时
 int tm_mday;//*日期
 int tm_mon; //*月份
 int tm_year; //*从1990年算起至今的年数
 int tm_wday; //*星期
 int tm_yday; //*从今年1月1日算起至今的天数
 int tm_isdst; //*日光节约时间的旗标
};

3. asctime()和ctime()函数产生形式的26字节字符串，这与date命令的系统默认输出形式类似：Tue Feb 10 18:27:38 2020/n/0.
4. strftime()将一个struct tm结构格式化为一个字符串。

----------------------------常用时间函数及举例---------------------------------
1、time函数
头文件：time.h
函数定义：time_t time (time_t *t)
说明：
返回从1970年1月1日的UTC时间从0时0分0妙算起到现在所经过的秒数。


2、ctime函数
定义：char *ctime(const time_t *timep);
说明：将参数所指的time_t结构中的信息转换成真实世界的时间日期表示方法，然后将结果以字符串形式返回。
注意这个是本地时间。

3、gmtime函数
定义：struct tm *gmtime(const time_t *timep);
说明：将参数timep所指的time_t结构中的信息转换成真实世界所使用的时间日期表示方法，然后将结果由结构tm返回。此函数返回的时间日期未经时区转换，而是UTC时间。

4、 strftime函数
#include <time.h> 
定义：  
size_t strftime(char *s, size_t max, const char *format,const struct tm *tm);
说明：
类似于snprintf函数，我们可以根据format指向的格式字符串，将struct tm结构体中信息输出到s指针指向的字符串中，最多为max个字节。当然s指针指向的地址需提前分配空间，比如字符数组或者malloc开辟的堆空间。
其中，格式化字符串各种日期和时间的详细的确切表示方法有如下多种，我们可以根据需要来格式化各种各样的含时间字符串。
    %a 星期几的简写
    %A 星期几的全称
    %b 月分的简写
    %B 月份的全称
    %c 标准的日期的时间串
    %C 年份的前两位数字
    %d 十进制表示的每月的第几天
    %D 月/天/年
    %e 在两字符域中，十进制表示的每月的第几天
    %F 年-月-日
    %g 年份的后两位数字，使用基于周的年
    %G 年分，使用基于周的年
    %h 简写的月份名
    %H 24小时制的小时
    %I 12小时制的小时
    %j 十进制表示的每年的第几天
    %m 十进制表示的月份
    %M 十时制表示的分钟数
    %n 新行符
    %p 本地的AM或PM的等价显示
    %r 12小时的时间
    %R 显示小时和分钟：hh:mm
    %S 十进制的秒数
    %t 水平制表符
    %T 显示时分秒：hh:mm:ss
    %u 每周的第几天，星期一为第一天 （值从0到6，星期一为0）
    %U 第年的第几周，把星期日做为第一天（值从0到53）
    %V 每年的第几周，使用基于周的年
    %w 十进制表示的星期几（值从0到6，星期天为0）
    %W 每年的第几周，把星期一做为第一天（值从0到53）
    %x 标准的日期串
    %X 标准的时间串
    %y 不带世纪的十进制年份（值从0到99）
    %Y 带世纪部分的十制年份
    %z，%Z 时区名称，如果不能得到时区名称则返回空字符。
    %% 百分号
返回值：
成功的话返回格式化之后s字符串的字节数，不包括null终止字符，但是返回的字符串包括null字节终止字符。否则返回0，s字符串的内容是未定义的。值得注意的是，这是libc4.4.4以后版本开始的。对于一些的老的libc库，比如4.4.1，如果给定的max较小的话，则返回max值。即返回字符串所能容纳的最大字节数。

5、 asctime函数
定义：
char *asctime(const struct tm *timeptr);
说明：
 将参数timeptr所指的struct tm结构中的信息转换成真实时间所使用的时间日期表示方法，结果以字符串形态返回。与ctime()函数不同之处在于传入的参数是不同的结构。
返回值：
 返回的也是UTC时间。

6、 localhost函数
struct tm *localhost(const time_t *timep);
取得当地目前的时间和日期


7、mktime函数
定义：time_t mktime(struct tm *timeptr);
说明：
 用来将参数timeptr所指的tm结构数据转换成从1970年1月1日的UTC时间从0时0分0妙算起到现在所经过的秒数。


8、 gettimeofday函数
定义：
int gettimeofday(struct timeval *tv,struct timezone *tz);
说明：
 把目前的时间由tv所指的结构返回，当地时区信息则放到有tz所指的结构中，
结构体timeval 定义如下：
struct timeval{
 long tv_sec; // 秒
 long tv_usec;  // 微秒
};

结构体timezone定义如下：
struct timezone{
 int tz_minuteswest; // 和greenwich时间差了多少分钟
 int tz_dsttime; // 日光节约时间的状态
}

************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<limits.h>
#include<math.h>
#include<string.h>
#include<sys/socket.h>
#include<stddef.h>
#include<locale.h>
#include<time.h>
#include<complex.h>


#define BUFLEN 255

/* struct timeval{ */
/*     long tv_sec; // 秒 */
/*     long tv_usec;  // 微秒 */
/* }; */

struct timezone{
    int tz_minuteswest; // 和greenwich时间差了多少分钟
    int tz_dsttime; // 日光节约时间的状态
};

int main(int argc, char *argv[])
{
    time_t timep;
   //-----------------1、time()函数----------------------------------------------
    long seconds = time(&timep);
    printf("---------1、time()函数--------------\n");
    printf("%ld\n",seconds);
    printf("%ld\n",timep);

   //-----------------2、ctime()函数----------------------------------------------
   // time_t timep;

    time(&timep);
    printf("---------2、ctime()函数--------------\n");
    printf("%s\n",ctime(&timep));


   //-----------------3、gmtime()函数----------------------------------------------
   char *wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
   // time_t timep;
   struct tm *p;
   // time(&timep);
    p = gmtime(&timep);
    printf("---------3、gmtime()函数--------------\n");
    printf("%d/%d/%d ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
    printf("%s %d:%d:%d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);


   //-----------------4、strftime()函数----------------------------------------------

    time_t t = time( 0 );
    char tmpBuf[BUFLEN];
    strftime(tmpBuf, BUFLEN, "%Y %m %d %H %M %S", localtime(&t)); //format date a
    printf("---------4、strftime()函数--------------\n");
    printf("%s\n",tmpBuf);


   //-----------------5、asctime()函数----------------------------------------------

    printf("---------5、asctime()函数--------------\n");
    printf("%s\n",asctime(gmtime(&timep)));

   //-----------------6、localtime()函数----------------------------------------------

    /* char *wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"}; */
    /* time_t timep; */
    /* struct tm *p; */

    time(&timep);
    p = localtime(&timep);
    printf("---------6、localtime()函数--------------\n");
    printf("%d/%d/%d ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
    printf("%s %d:%d:%d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);



   //-----------------7、mktime()函数----------------------------------------------
    time(&timep);
    printf("---------7、mktime()函数--------------\n");
    printf("time():%ld\n",timep);
    p = localtime(&timep);
    timep = mktime(p);
    printf("time()->localtime()->mktime():%ld\n",timep);


   //-----------------8、gettimeofday()函数----------------------------------------------
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv,&tz);
    printf("---------7、mktime()函数--------------\n");
    printf("tv_sec :%d\n",tv.tv_sec);
    printf("tv_usec: %d\n",tv.tv_usec);
    printf("tz_minuteswest:%d\n",tz.tz_minuteswest);
    printf("tz_dsttime:%d\n",tz.tz_dsttime);


    return 0;
}
