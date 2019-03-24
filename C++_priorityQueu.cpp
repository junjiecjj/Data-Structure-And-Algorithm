/*************************************************************************
>> File Name: 向量.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.17
************************************************************************/

#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<list>
#include<forward_list>
#include<deque>
#include<stack>
#include<queue>//优先级队列priority_queue包含在queue库中
#include<algorithm>
#include<numeric>

int main(int argc,char *argv[])
{
    priority_queue<int> Pque;
    for(int i = 0; i< 10; i++)
    {
        Pque.push(i+1);
    }
    Pque.push(100);
    Pque.push(231);
    Pque.push(21);
    Pque.push(190);
    cout << "优先级队列大小为:" << Pque.size() << endl;
    cout << "优先级最大的元素为:" << Pque.top()  << endl;
    cout << "删除优先级最大的元素" << endl;                         //Pque.pop()返回值为void
    Pque.pop();

    cout << "现在优先级最大的元素为:" << Pque.top()  << endl;
    Pque.pop();
    cout << "队列是否为空:" << Pque.empty() << endl;

    //Pque.sort();
    //Pque.reverse();
    //auto res = find(Pque.begin(),Pque.end(), 3);
    //int sum  = accumulate(Pque.begin(),Pque.end(),0)

    //Pque.clear()          //优先队列没有Pque.clear()
    return 0;
}

/**
 * 输出为:

优先级队列大小为:14
优先级最大的元素为:231
删除优先级最大的元素
现在优先级最大的元素为:190
队列是否为空:0

*/
