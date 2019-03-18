/*************************************************************************
>> File Name: 数组.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.18
************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<array>


void show(const array<int, 10> Array)
{
    for(auto i : Array)
    {
        cout << i << "  ";                              //array有array.begin(),array.cbegin(),array.rgegin(),array.crbegin()等
    }
    cout << endl;
}
int main(int argc, char *argv[])
{
    array<int, 10> Array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    show(Array);
    cout << "数组大小为:" << Array.size() << endl;
    cout << "数组最大容量为:" << Array.max_size() << endl;

    //cout << "向数组尾部添加元素:" << endl;              //array不能改变大小，所以没有array.pop_back(),array.pop_front(),array.push_back(),array_push_front()等
    //Array.push_back(12);
    //show(Array);

    //cout << "向数组首部添加元素:" << endl;

    //Array.push_front(13);
    //cout << "数组大小为:" << Array.size() << endl;         //array有array.size(),array.max_size(), array.at(n)和array[n]等操作

    //cout << "数组最大容量为:" << Array.max_size() << endl;

    cout << "数组最后的元素为:" << Array.back() << endl;
    cout << "数组首部的元素为:" << Array.front() << endl;

    cout << "数组第四个元素为:" << Array.at(3) << endl;
    cout << "数组第六个元素为:" << Array[5] << endl;

    cout << "利用array.at(n)和arry[n]改变数组" << endl;

    Array.at(3) = 33;
    Array[5] = 77;

    show(Array);
    return 0;
}
