/*************************************************************************
>> File Name: pthread.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com

>> Created Time: 2021年03月05日 星期五 19时00分52秒
>> Last Modified : 1970年01月01日 星期四 07时59分59秒
>> 此程序的功能是：
************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#include <pthread.h>
#include <iostream>
#include <string>

using namespace std;

pthread_t ntid;

void printids(const char *s){
	pid_t		pid;
	pthread_t	tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid,
	  (unsigned long)tid, (unsigned long)tid);
}


void *thr_fn(void *arg){
	printids("new thread: ");
	cout << "Change to C++ code!!" << endl;
	return((void *)0);
}

int main(void){
	int		err;
    //第四个参数为NULL，说明没有向线程函数传参数。
	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if (err != 0)
		err_exit(err, "can't create thread");
	printids("main thread:");
	sleep(1);
	exit(0);
}
