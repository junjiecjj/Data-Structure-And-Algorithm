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


//void show(const stack<int> stack1)
//{
//    for( auto i : stack1 )
//    {
  //      cout << i <<"  ";                        //stack没有stack<T>::iterator迭代器
  //                                                   const_iterator也没有
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
    std::cout << "栈的大小:" << Stack.size() << endl;
    //cout << "栈的max_size:" << Stack.max_size() << endl;         //stack<T>没有.max_size成员
    cout << "栈顶元素:";
    cout << Stack.top() << endl;
    cout << "删除栈顶元素" << endl;
    Stack.pop();

    cout << "栈顶元素:" ;
    cout << Stack.top() << endl;
    cout << "删除栈顶元素" << endl;
    Stack.pop();                    //返回void

    std::cout << "栈的元素数量:" << Stack.size() << endl;
    //Stack.sort();
    //sort(Stack.begin(),Stack.end());
    //find(Stack.begin(),Stack.end());
    //accumulate(Stack.begin(),Stack.end(),0);
    //Stack.reverse();
    cout << "栈顶元素:";
    cout << Stack.top() << endl;
    cout << "删除栈顶元素" << endl;
    Stack.pop();

    //cout << "栈的第三个元素为:" << Stack[2] << endl;   栈不支持stack.at(n)和stack[n]
    
    cout << "栈是否为空,0为非空,1为空:" << Stack.empty() << endl;
    std::cout << "栈的元素数量:" << Stack.size() << endl;

    //cout << "清空栈" << endl;
    //Stack.clear();                        //栈没有stack.clear()

    return 0;
}

/*
输出为:

栈的大小:9
栈顶元素:9
删除栈顶元素
栈顶元素:8
删除栈顶元素
栈的元素数量:7
栈顶元素:7
删除栈顶元素
栈是否为空,0为非空,1为空:0
栈的元素数量:6
*/
