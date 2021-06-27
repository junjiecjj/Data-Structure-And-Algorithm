/***************************************************
           Copyright (C)  公众号: 一口linux
https://mp.weixin.qq.com/s/nbpVyJrzayqV32X8JFL3Rg
现在我们利用这些时间函数，来实现一个定时执行某个任务得功能。

功能

程序运行时要记录当前日志文件的最后修改时间；
每个 10 秒钟就检查下 log 文件是否被修改，如果没有被修改就休眠 10 秒钟；
如果 log 文件被修改了，就将当前的日志文件拷贝成备份文件，备份文件名字加上当前时间；
通过 curl 发送给 ftp 服务器；
删除备份文件，重复步骤 2。
***************************************************/
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct stat ST;
unsigned long last_mtime;

/*用户名密码暂时写死，实际应该保存在配置文件*/
char name[32]="user";
char pass[32] ="123456";
char ip[32]     ="192.168.43.117";
char filename[32]="t.log";
char dstfile[256]  ={0};

int init(void)
{
 //准备结构体
 ST status;

 //调用stat函数
 int res = stat(filename,&status);
 if(-1 == res)
 {
  perror("error:open file fail\n");
  return 0;
 }
 last_mtime = status.st_mtime;
 printf("init time:%s \n",ctime(&last_mtime));
 return 1;
}

int  check_file_change(void)
{
 //准备结构体
 ST status;

 //调用stat函数
 int res = stat(filename,&status);
 if(-1 == res)
 {
  perror("error:open file fail\n");
  return 0;
 }
// printf("old:%s new:%s",ctime(&last_mtime),ctime(&status.st_mtime));
 if(last_mtime == status.st_mtime)
 {
  printf("file not change\n");
  return 0;
 }else{
  printf("file updated\n");
  last_mtime = status.st_mtime;
  return 1;
 }

}
void file_name_add_time(void)
{
 ST status;
 time_t t;
 struct tm *tblock;
 char cmd[1024]={0};

 t = time(NULL);
 tblock = localtime(&t);

 sprintf(dstfile,"t-%d-%d-%d-%d-%d-%d.log",
  tblock->tm_year+1900,
  tblock->tm_mon,
  tblock->tm_mday,
  tblock->tm_hour,
  tblock->tm_min,
  tblock->tm_sec);
 sprintf(cmd,"cp %s %s",filename,dstfile);
// printf("cdm=%s\n",cmd);
 system(cmd);
}
int main(void)
{

 char cmd[1024]={0};

 init();
 while(1)
 {
  if(check_file_change() == 1)
  {
   file_name_add_time();
   sprintf(cmd,"curl -u %s:%s ftp://%s/ -T %s",name,pass,ip,dstfile);
 //  printf("cdm=%s\n",cmd);
   system(cmd);
   unlink(dstfile);
  }
  sleep(10);
 }
}