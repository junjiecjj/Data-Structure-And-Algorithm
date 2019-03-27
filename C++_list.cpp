/*************************************************************************
>> File Name: 链表.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.13
************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<list>
#include<stack>
#include<forward_list>
#include<deque>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
//using  std::cin;
//using std::cout;
//using std::list;
//using std::endl;

#define max 100;

void show(const list<int> liST)
{
    for( auto i : liST )
    {
        cout << i <<"  ";
    }
    cout << "\n\n";

}

void show1(const list<int> liST)
{
    //list<int>::const_iterator it;
    for(auto it = liST.cbegin(); it != liST.cend(); ++it)
    {
        printf("%d  ",*it);
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
    list<int> list1;
    for(int i = 0; i < 7; i++)
    {
        list1.push_back(i);
    }

    for(int i = 7; i < 14; i++)
    {
        list1.push_front(i);
    }
    list1.push_front(14);
    list1.push_front(15);
    list1.push_front(16);
    list1.push_back(17);
    list1.push_back(18);
    list1.push_back(19);
    list1.push_back(20);

    //list没有list.at(n)和list[n]
    
    cout << "list1的大小为:" << list1.size() << endl;
    cout << "list1最大可保存的元素数量为:" << list1.max_size() << endl;
    cout << "list1是否为空，1为空，0为非空:" << list1.empty() << endl;

    cout << "打印链表\n";
    show1(list1);

    cout <<"从尾部删除元素" << endl; 
    cout << list1.back() << endl;list1.pop_back();
    cout << list1.back() << endl;list1.pop_back();
    cout << "打印链表\n";
    show(list1);

    cout <<"从头部删除元素" << endl; 
    cout << list1.front() << endl;list1.pop_front();
    cout << list1.front() << endl;list1.pop_front();
    cout << "打印链表\n";
    show1(list1);

    cout << "反转并打印链表\n";
    list1.reverse();
    show1(list1);

    cout << "排序并打印链表\n";
    list1.sort();
    show1(list1);

    auto result = find(list1.cbegin(), list1.cend(), 7);
    for(auto i = result; i != list1.end(); i++)
        cout << *i << "  ";
    cout << endl;
    cout << "找到 7 了:" << *result << endl;

    int sum  = accumulate(list1.cbegin(), list1.cend(), 0);
    cout << "单项链表和为:" << sum << endl;

    cout << "清空list1" << endl;
    list1.clear();
    cout << "list1的大小为:" << list1.size() << endl;

    show(list1);
    return 0;
}

/*

*输出为:


list1的大小为:21
list1最大可保存的元素数量为:768614336404564650
list1是否为空，1为空，0为非空:0
打印链表
16  15  14  13  12  11  10  9  8  7  0  1  2  3  4  5  6  17  18  19  20  

从尾部删除元素
20
19
打印链表
16  15  14  13  12  11  10  9  8  7  0  1  2  3  4  5  6  17  18  

从头部删除元素
16
15
打印链表
14  13  12  11  10  9  8  7  0  1  2  3  4  5  6  17  18  

反转并打印链表
18  17  6  5  4  3  2  1  0  7  8  9  10  11  12  13  14  

排序并打印链表
0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  17  18  

7  8  9  10  11  12  13  14  17  18  
找到 7 了:7
单项链表和为:140
清空list1
list1的大小为:0


*/
