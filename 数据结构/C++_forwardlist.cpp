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
#define MAXLEN 1000;

//using  std::cin;
//using std::cout;
//using std::list;
//using std::endl;

void show(const forward_list<int> liST)
{
    for( auto i : liST )
    {
        cout << i <<"  ";
    }
    cout << endl;

}

void show1(const forward_list<int> liST)
{
    for(auto it = liST.cbegin(); it != liST.cend(); ++it)
    {
        printf("%d  ",*it);
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
    forward_list<int> list1;
    for(int i = 0; i < 10; i++)
    {
        list1.push_front(i);
    }
    list1.push_front(20);
    list1.push_front(19);
    list1.push_front(18);
    list1.push_front(17);
    list1.push_front(16);
    list1.push_front(15);
    list1.push_front(14);


    //cout << list1.at(3) << endl;           //forward_list没有list.at(n)和list[n]
    //cout << list1[3] << endl;
    
    //for(int i = 7; i < 10; i++)
    //{
    //    list1.push_back(i);                 //forward_list没有puch_back
    //}

    //cout << "list1的大小为:" << list1.size() << endl;      //forward_list没有list.size()但有list.max_size()

    cout << "list1最大可保存的元素数量为:" << list1.max_size() << endl;
    cout << "list1是否有元素:" << list1.empty() << endl;
    cout<< "打印单项链表\n";
    show(list1);
    //cout <<"从尾部删除元素" << endl; 
    //cout << list1.back() << endl;list1.pop_back();                    //forward_list没有pop_back，也没有back
    //cout << list1.back() << endl;list1.pop_back();
    cout <<"从头部删除元素" << endl; 
    cout << list1.front() << endl;list1.pop_front();
    cout << list1.front() << endl;list1.pop_front();

    cout<< "打印单项链表\n";
    show(list1);
    cout << "单向链表是否为空,0代表非空，1代表空:" << list1.empty()  << endl;

    cout << "反转链表,然后打印链表\n";
    list1.reverse();
    show1(list1);

    cout << "排序并打印单项链表\n";
    list1.sort();
    show(list1);

    auto result = find(list1.cbegin(), list1.cend(), 7);
    for(auto i = result; i != list1.end(); i++)
        cout << *i << " ";
    cout << endl;
    cout << "找到 7 了:" << *result << endl;


    int sum  = accumulate(list1.cbegin(), list1.cend(), 0);
    cout << "单项链表和为:" << sum << endl;

    cout << "清空list1" << endl;
    list1.clear();
    show1(list1);
    return 0;
}

/*
输出为:


list1最大可保存的元素数量为:1152921504606846975
list1是否有元素:0
打印单项链表
14  15  16  17  18  19  20  9  8  7  6  5  4  3  2  1  0  
从头部删除元素
14
15
打印单项链表
16  17  18  19  20  9  8  7  6  5  4  3  2  1  0  
单向链表是否为空,0代表非空，1代表空:0
反转链表,然后打印链表
0  1  2  3  4  5  6  7  8  9  20  19  18  17  16  
排序并打印单项链表
0  1  2  3  4  5  6  7  8  9  16  17  18  19  20  
7 8 9 16 17 18 19 20 
找到 7 了:7
单项链表和为:135
清空list1

 */
