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
#include<vector>
#include<string>
#include<list>
#include<forward_list>
#include<array>
#include<deque>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>

void show(const array<int, 18> Array)
{
    cout << "打印数组\n";
    for(auto i : Array)
    {
        cout << i << "  ";                              //array有array.begin(),array.cbegin(),array.rgegin(),array.crbegin()等
    }
    cout << "\n\n";
}
int main(int argc, char *argv[])
{
    array<int, 18> Array = {18, 20, 13, 4, 21, 16, 7, 8, 11,32,10,12,100,65, 10,33,76,1};
    show(Array);
    cout << "数组大小为:" << Array.size() << endl;
    cout << "数组最大容量为:" << Array.max_size() << endl;

    //cout << "向数组尾部添加元素:" << endl;              //array不能改变大小，所以没有array.pop_back(),array.pop_front(),array.push_back(),array_push_front()等
    //Array.push_back(12);
    //show(Array);

    //cout << "向数组首部添加元素:" << endl;

    //Array.push_front(13);
    //cout << "数组大小为:" << Array.size() << endl;
    //cout << "数组最大容量为:" << Array.max_size() << endl;

    cout << "数组最后的元素为:" << Array.back() << endl;
    cout << "数组首部的元素为:" << Array.front() << endl;           //array有array.size(),array.max_size(), array.at(n)和array[n],array.back(),array.front()等操作

    cout << "数组第四个元素为:" << Array.at(3) << endl;
    cout << "数组第六个元素为:" << Array[5] << endl;
    cout << "数组是否为空,1为空，0为非空:" << Array.empty() << endl; 

    cout << "利用array.at(n)和arry[n]改变数组" << endl;

    Array.at(3) = 33;
    Array[5] = 77;

    show(Array);

    auto result = find(Array.cbegin(), Array.cend(), 7);
    for(auto i = result; i != Array.end(); i++)
        cout << *i << "  ";
    cout << endl;
    cout << "找到 7 了:" << *result << endl;

    cout << "反转并打印数组\n";
    reverse(Array.begin(),Array.end());
    show(Array);

    cout << "排序并打印数组\n";
    sort(Array.begin(),Array.end());
    show(Array);

    int sum  = accumulate(Array.cbegin(), Array.array::cend(), 0);
    cout << "数组和为:" << sum << endl;

    cout << "清空数组" << endl;
    //Array.clear();                      //因为数组不能改变大小，所以没有array.clear()
    cout << "数组大小为:" << Array.size() << endl;

    return 0;
}
/*
输出为:


打印数组
18  20  13  4  21  16  7  8  11  32  10  12  100  65  10  33  76  1  

数组大小为:18
数组最大容量为:18
数组最后的元素为:1
数组首部的元素为:18
数组第四个元素为:4
数组第六个元素为:16
数组是否为空,1为空，0为非空:0
利用array.at(n)和arry[n]改变数组
打印数组
18  20  13  33  21  77  7  8  11  32  10  12  100  65  10  33  76  1  

7  8  11  32  10  12  100  65  10  33  76  1  
找到 7 了:7
反转并打印数组
打印数组
1  76  33  10  65  100  12  10  32  11  8  7  77  21  33  13  20  18  

排序并打印数组
打印数组
1  7  8  10  10  11  12  13  18  20  21  32  33  33  65  76  77  100  

数组和为:547
清空数组
数组大小为:18


*/
