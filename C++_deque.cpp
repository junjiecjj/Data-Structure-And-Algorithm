/*************************************************************************
>> File Name: 双端队列.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.15
************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<deque>

void show(const deque<int> Deque)
{
    cout << "打印队列" << endl;
    for(auto it : Deque)
    {
        cout << it << "  ";
    }
    cout << endl;
}

void show1(deque<int> Deque)
{
    cout << "打印队列" << endl;
    deque<int>::const_iterator it;
    for(it = Deque.cbegin(); it != Deque.cend(); ++it)          //deque支持迭代器,deque<int>::iterator和deque<int>::const_iterator
    {
        cout << *it << "  " ;
    }
    printf("\n");
    //for(auto it = liST.cbegin(); it != liST.cend(); ++it)
    //{
    //    printf("%d  ",*it);
    //}
    //printf("\n");
}
int main(int argc,char *argv[])
{
    deque<int> Deque;
    for(int i  = 0; i < 5; i++)
    {
        Deque.push_back(i+1);                             //deque.push_back(i)向队尾添加元素
    }
    for(int i = 5; i < 10; i++)
    {
        Deque.push_front(i+1);                              //deque.push_front(i)向队首添加元素
    }
    show(Deque);
    cout << "队列大小为:" << Deque.size() << endl;           //deque.size()返回队列元素数量
    cout << "队列能保存的最大元素数量为:" << Deque.max_size() << endl;           //deque.size()返回队列能保存的最大元素数量

    cout << "队尾元素：" << Deque.back() << endl;
    cout << "删除队尾元素pop_back()" << endl;
    Deque.pop_back();                                  // deque.pop_back()删除队尾元素,返回void,
    show(Deque);

    cout << "队首元素:" << Deque.front() << endl;
    cout << "删除队首元素pop_front()" << endl;
    Deque.pop_front();                                      // deque.pop_front()删除队尾元素,返回void,

    show(Deque);

    cout << "队列大小为:" << Deque.size() << endl;           //deque.size()返回队列元素数量
    cout << "队列中第4个元素为:" << Deque[3] << endl;            //deque.at(n)和deque[n]返回队列第n+1个元素
    cout << "队列中第7个元素为:" << Deque.at(6) << endl;
    return 0;
}
