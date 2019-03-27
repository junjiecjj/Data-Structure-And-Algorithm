/*********************************************************************
>> File Name: 双端队列.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.15
*********************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<forward_list>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>


void show(const deque<int> Deque)
{
    for(auto it : Deque)
    {
        cout << it << "  ";
    }
    cout << "\n\n";
}

void show1(deque<int> Deque)
{
    deque<int>::const_iterator it;
    for(it = Deque.cbegin(); it != Deque.cend(); ++it)          //deque支持迭代器,deque<int>::iterator和deque<int>::const_iterator
    {
        cout << *it << "  " ;
    }
    printf("\n\n");
    //for(auto it = liST.cbegin(); it != liST.cend(); ++it)
    //{
    //    printf("%d  ",*it);
    //}
    //printf("\n");
}
int main(int argc,char *argv[])
{
    deque<int> Deque;
    for(int i  = 0; i < 7; i++)
    {
        Deque.push_back(i+1);                             //deque.push_back(i)向队尾添加元素
    }
    for(int i = 5; i < 14; i++)
    {
        Deque.push_front(i+1);                              //deque.push_front(i)向队首添加元素
    }
    Deque.push_front(15);
    Deque.push_front(16);
    Deque.push_front(17);
    Deque.push_front(18);
    Deque.push_back(19);
    Deque.push_back(20);
    Deque.push_back(21);
    Deque.push_back(22);
    Deque.push_front(23);

    cout << "打印队列\n";
    show(Deque);
    cout << "队列大小为:" << Deque.size() << endl;           //deque.size()返回队列元素数量
    cout << "队列能保存的最大元素数量为:" << Deque.max_size() << endl;           //deque.size()返回队列能保存的最大元素数量

    cout << "队尾元素：" << Deque.back() << endl;
    cout << "删除队尾元素pop_back()" << endl;
    Deque.pop_back();                                  // deque.pop_back()删除队尾元素,返回void,
    cout << "打印队列\n";
    show(Deque);

    cout << "队首元素:" << Deque.front() << endl;
    cout << "删除队首元素pop_front()" << endl;
    Deque.pop_front();                                      // deque.pop_front()删除队尾元素,返回void,
    cout << "打印队列\n";
    show(Deque);

    cout << "队列大小为:" << Deque.size() << endl;           //deque.size()返回队列元素数量
    cout << "队列中第4个元素为:" << Deque[3] << endl;            //deque.at(n)和deque[n]返回队列第n+1个元素
    cout << "队列中第7个元素为:" << Deque.at(6) << endl;

    cout << "通过Deque.at(n)和Deque[n]改变Deque" << endl;
    Deque.at(4) = 78;
    Deque.at(7) = 99;

    show(Deque);
    cout << "双端队列是否为空，1为空,0为非空:" << Deque.empty() << endl;

    auto result = find(Deque.cbegin(), Deque.cend(), 7);
    for(auto i = result; i != Deque.end(); i++)
        cout << *i << "  ";
    cout << endl;
    cout << "找到 7 了:" << *result << endl;

    cout << "反转并打印队列\n";
    reverse(Deque.begin(),Deque.end());
    show(Deque);

    cout << "排序并打印队列\n";
    sort(Deque.begin(),Deque.end());
    show(Deque);

    int sum  = accumulate(Deque.cbegin(), Deque.cend(), 0);
    cout << "单项链表和为:" << sum << endl;

    cout << "清空双端队列" << endl;
    Deque.clear();
    cout << "队列大小为:" << Deque.size() << endl;
    show(Deque);

    return 0;
}
/*

打印队列
23  18  17  16  15  14  13  12  11  10  9  8  7  6  1  2  3  4  5  6  7  19  20  21  22  

队列大小为:25
队列能保存的最大元素数量为:4611686018427387903
队尾元素：22
删除队尾元素pop_back()
打印队列
23  18  17  16  15  14  13  12  11  10  9  8  7  6  1  2  3  4  5  6  7  19  20  21  

队首元素:23
删除队首元素pop_front()
打印队列
18  17  16  15  14  13  12  11  10  9  8  7  6  1  2  3  4  5  6  7  19  20  21  

队列大小为:23
队列中第4个元素为:15
队列中第7个元素为:12
通过Deque.at(n)和Deque[n]改变Deque
18  17  16  15  78  13  12  99  10  9  8  7  6  1  2  3  4  5  6  7  19  20  21  

双端队列是否为空，1为空,0为非空:0
7  6  1  2  3  4  5  6  7  19  20  21  
找到 7 了:7
反转并打印队列
21  20  19  7  6  5  4  3  2  1  6  7  8  9  10  99  12  13  78  15  16  17  18  

排序并打印队列
1  2  3  4  5  6  6  7  7  8  9  10  12  13  15  16  17  18  19  20  21  78  99  

单项链表和为:396
清空双端队列
队列大小为:

*/
