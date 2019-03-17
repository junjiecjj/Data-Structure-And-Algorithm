/*************************************************************************
>> File Name: 链表.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.13
这是介绍C++中双向链表list的使用方法的代码
************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<list>


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
    cout << endl;

}

void show1(const list<int> liST)
{
    list<int>::const_iterator it;
    for(it = liST.cbegin(); it != liST.cend(); ++it)
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
    list<int> list1;
    for(int i = 0; i < 7; i++)
    {
        list1.push_back(i);
    }

    for(int i = 7; i < 10; i++)
    {
        list1.push_front(i);
    }

    //list没有list.at(n)和list[n]
    
    cout << "list1的大小为:" << list1.size() << endl;
    cout << "list1最大可保存的元素数量为:" << list1.max_size() << endl;
    cout << "list1是否有元素:" << list1.empty() << endl;
    show(list1);
    cout <<"从尾部删除元素" << endl; 
    cout << list1.back() << endl;list1.pop_back();
    cout << list1.back() << endl;list1.pop_back();
    cout <<"从头部删除元素" << endl; 
    cout << list1.front() << endl;list1.pop_front();
    cout << list1.front() << endl;list1.pop_front();

    //cout << "清空list1" << endl;
    //list1.clear();
    show1(list1);
    return 0;
}
