/*************************************************************************
>> File Name: 栈.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.15
************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>

#include<stack>



//void show(const stack<int> stack1)
//{
//    for( auto i : stack1 )
//    {
  //      cout << i <<"  ";                        //stack没有stack<T>::iterator迭代器
  //                                                   也没有const_iterator
    //}
   // cout << endl;

//}



int main(int argc,char *argv[])
{
    stack<int> Stack;
    for(int i = 1; i < 10; i++)
    {
        Stack.push(i);
    }
    std::cout << "栈的大小" << Stack.size() << endl;
    //cout << "栈的max_size:" << Stack.max_size() << endl;         //stack<T>没有.max_size成员
    cout << Stack.top() << endl;
    Stack.pop();

    cout << Stack.top() << endl;
    Stack.pop();

    cout << Stack.top() << endl;
    Stack.pop();

    std::cout << Stack.size() << endl;

    return 0;
}
