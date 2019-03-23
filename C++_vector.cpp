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
#include<queue>
#include<map>
#include<set>

void show(const vector<int> Vec)
{
    for(auto i: Vec)        //vector支持vector.begin()、vector.end()、vector.cbegin()、vector.cend()、vector.rbegin()、vector.rend()、vector.crbegin()、vector.crend()
    {
        cout << i << "  ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    //vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    //vector<int> vec(10,1);
    vector<int> vec;
    for(int i = 0; i < 10; i++)
        vec.push_back(i+1);                     
    //vec.push_front(i+1);                                          //vector<int>不支持push_front()
    cout << "vector的容量大小为:" << vec.size() << endl;
    cout << "vector的最大容量为:" << vec.max_size() << endl;
    show(vec);

    cout << "vector最后的元素为:" << vec.back() << endl;
    cout << "删除vector最后的元素:" << endl;
    vec.pop_back();
    show(vec);

    cout << "vector最后的元素为:" << vec.back() << endl;
    cout << "删除vector最后的元素:" << endl;
    vec.pop_back();
    show(vec);

    cout << "vector首部的元素为:" << vec.front() << endl;
    cout << "不能用vec.pop_front()删除vector首部的元素:" << endl;
    show(vec);

    cout << "第三个元素为:" << vec.at(2) << endl;
    cout << "第5个元素为:" << vec[4] << endl;

    cout << "改变向量vec的第3个第5个元素"  << endl;
    vec.at(2) = 33;
    vec[4] = 99;

    show(vec);

    cout << "清空向量" << endl;
    vec.clear();
    cout << "vector的容量大小为:" << vec.size() << endl;
    return 0;

}
/*
 输出为:

vector的容量大小为:10
vector的最大容量为:4611686018427387903
1  2  3  4  5  6  7  8  9  10  
vector最后的元素为:10
删除vector最后的元素:
1  2  3  4  5  6  7  8  9  
vector最后的元素为:9
删除vector最后的元素:
1  2  3  4  5  6  7  8  
vector首部的元素为:1
不能用vec.pop_front()删除vector首部的元素:
1  2  3  4  5  6  7  8  
第三个元素为:3
第5个元素为:5
改变向量vec的第3个第5个元素
1  2  33  4  99  6  7  8  
清空向量
vector的容量大小为:0

*/
