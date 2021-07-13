/*************************************************************************
>> File Name: mmap.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
>> Created Time: 2021年02月28日 星期日 19时40分52秒
>> 此程序的功能是：
************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>


int main(int argc, char *argv[])
{
    int fd;
    void *start;
    struct stat sb;
    fd = open("/etc/passwd",O_RDONLY);
    fstat(fd,&sb);
    start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(start == MAP_FAILED)
    {
        return 0;
    }
    printf("%s",start);
    munma(start, sb.st_size);
    close(fd);
    return 0;
}
