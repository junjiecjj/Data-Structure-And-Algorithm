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

#include<forward_list>

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

    //cout << list1.at(3) << endl;                             //forward_list没有list.at(n)和list[n]
    //cout << list1[3] << endl;
    
    //for(int i = 7; i < 10; i++)
    //{
    //    list1.push_back(i);                                  //forward_list没有puch_back
    //}

    //cout << "list1的大小为:" << list1.size() << endl;         //forward_list没有list.size()但有list.max_size()
    cout << "list1最大可保存的元素数量为:" << list1.max_size() << endl;
    cout << "list1是否有元素:" << list1.empty() << endl;
    show(list1);
    //cout <<"从尾部删除元素" << endl; 
    //cout << list1.back() << endl;list1.pop_back();           //forward_list没有pop_back，也没有back
    //cout << list1.back() << endl;list1.pop_back();
    cout <<"从头部删除元素" << endl; 
    cout << list1.front() << endl;list1.pop_front();
    cout << list1.front() << endl;list1.pop_front();

    //cout << "清空list1" << endl;
    //list1.clear();
    show1(list1);
    return 0;
}
