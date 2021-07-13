#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *function(void *arg);
pthread_mutex_t mutex;
int counter = 0;
int main(int argc, char *argv[])
{
    int rc1,rc2;

    char *str1="wenhaoll";
    char *str2="linglong";
    pthread_t thread1,thread2;

    pthread_mutex_init(&mutex,NULL);
    if((rc1 = pthread_create(&thread1,NULL,function,str1)))
    {
        fprintf(stdout,"thread 1 create failed: %d\n",rc1);
    }

    if(rc2=pthread_create(&thread2,NULL,function,str2))
    {
        fprintf(stdout,"thread 2 create failed: %d\n",rc2);
    }

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}

 //可以尝试将关于锁的操作去掉，有什么效果
void *function(void *arg)
{
    char *m;
    m = (char *)arg;
    pthread_mutex_lock(&mutex);
    while(*m != '\0')
    {
        printf("%c",*m);
        fflush(stdout);
        m++;
        sleep(1);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
}