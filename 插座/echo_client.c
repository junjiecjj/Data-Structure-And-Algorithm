/*************************************************************************
>> File Name: echo_client.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com

>> Created Time: 2021年03月06日 星期六 14时19分46秒
>> Last Modified : 1970年01月01日 星期四 07时59分59秒
>> 此程序的功能是：
************************************************************************/

#include <stdio.h>
#include <string.h>
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
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(9600);

    if (connect(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        printf("connect() error");
        exit(1);
    }

    while (1)
    {
        fputs("请输入您的信息,按Q键退出\n", stdout);
        fgets(message, 1024, stdin);

        //因为fgets会保留输入中换行符,故判断加\n
        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
        {
            break;
        }

        write(serv_sock, message, sizeof(message));
        read(serv_sock, message, BUF_SIZE - 1);
        printf("Message from server: %s\n", message);
    }

    close(serv_sock);
    return 0;
}
