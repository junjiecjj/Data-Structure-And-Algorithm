/*************************************************************************
>> File Name: C_Gethostname.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com

>> Created Time: 2021年03月08日 星期一 09时57分12秒
>> Last Modified : 1970年01月01日 星期四 07时59分59秒
>> 此程序的功能是：
************************************************************************/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>

extern int h_errno;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Use example: %s www.google.com\n", *argv);
        return -1;
    }

    char *name = argv[1];
    struct hostent *hptr;

    hptr = gethostbyname(name);
    if (hptr == NULL)
    {
        printf("gethostbyname error for host: %s: %s\n", name, hstrerror(h_errno));
        return -1;
    }
    //输出主机的规范名
    printf("\tofficial: %s\n", hptr->h_name);

    //输出主机的别名
    char **pptr;
    char str[INET_ADDRSTRLEN];
    for (pptr = hptr->h_aliases; *pptr != NULL; pptr++)
    {
        printf("\ttalias: %s\n", *pptr);
    }

    //输出ip地址
    switch (hptr->h_addrtype)
    {
    case AF_INET:
        pptr = hptr->h_addr_list;
        for (; *pptr != NULL; pptr++)
        {
            printf("\taddress: %s\n",
                   inet_ntop(hptr->h_addrtype, hptr->h_addr, str, sizeof(str)));
        }
        break;
    default:
        printf("unknown address type\n");
        break;
    }

    return 0;
}