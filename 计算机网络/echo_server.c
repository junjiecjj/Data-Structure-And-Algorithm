/*************************************************************************
>> File Name: echo_server.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com

>> Created Time: 2021年03月06日 星期六 10时34分20秒
>> Last Modified : 2021年03月06日 星期六 10时35分29秒
>> 此程序的功能是：
************************************************************************/

#include <stdio.h>
#include<string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 5

int main(int argc, char *argv[])
{
    char message[BUF_SIZE];
    int str_len, i;

    struct sockaddr_in serv_addr, clnt_addr;

    int serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
    {
        printf("socket() error");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(9600);

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        printf("bind() error");
        exit(1);
    }

    if (listen(serv_sock, 5) == 1)
    {
        printf("listen() error");
        exit(1);
    }

    int clnt_addr_sz = sizeof(clnt_addr);
    for (i = 0; i < 5; i++)
    {
        int clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_sz);
        if (clnt_sock == -1)
        {
            printf("accept() error");
            exit(1);
        }
        while (str_len = read(clnt_sock, message, BUF_SIZE) > 0)
        {
            write(clnt_sock, message, str_len);
        }
        close(clnt_sock);
    }
    close(serv_sock);
    return 0;
}
