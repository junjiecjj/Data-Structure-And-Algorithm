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
#include<algorithm>
#include<numeric>

void show(const vector<int> Vec)
{
    cout << "打印向量\n";
    for(auto i: Vec)        //vector支持vector.begin()、vector.end()、vector.cbegin()、vector.cend()、vector.rbegin()、vector.rend()、vector.crbegin()、vector.crend()
    {
        cout << i << "  ";
    }
    cout << "\n\n";
}

int main(int argc, char *argv[])
{
    //vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    //vector<int> vec(10,1);
    vector<int> vec;
    for(int i = 0; i < 10; i++)
        vec.push_back(i+1);
    vec.push_back(20);
    vec.push_back(19);
    vec.push_back(14);
    vec.push_back(13);
    vec.push_back(12);
    vec.push_back(18);
    vec.push_back(17);
    vec.push_back(16);
    vec.push_back(22);
    vec.push_back(15);

    show(vec);
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
    cout << "向量是否为空,1为空，0为非空:" << vec.empty() << endl;

    cout << "vector首部的元素为:" << vec.front() << endl;
    cout << "不能用vec.pop_front()删除vector首部的元素:" << endl;
    show(vec);

    cout << "第三个元素为:" << vec.at(2) << endl;
    cout << "第5个元素为:" << vec[4] << endl;

    cout << "改变向量vec的第3个第5个元素"  << endl;
    vec.at(2) = 33;
    vec[4] = 99;
    show(vec);

    auto result = find(vec.cbegin(), vec.cend(), 7);
    for(auto i = result; i != vec.end(); i++)
        cout << *i << "  ";
    cout << endl;
    cout << "找到 7 了:" << *result << endl;

    cout << "反转并打印向量\n";
    reverse(vec.begin(),vec.end());
    show(vec);

    cout << "排序并打印向量\n";
    sort(vec.begin(),vec.end());
    show(vec);

    int sum  = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << "向量和为:" << sum << endl;



    cout << "清空向量" << endl;
    vec.clear();
    cout << "vector的容量大小为:" << vec.size() << endl;
    return 0;

}
/*
 输出为:

打印向量
1  2  3  4  5  6  7  8  9  10  20  19  14  13  12  18  17  16  22  15  

vector的容量大小为:20
vector的最大容量为:4611686018427387903
打印向量
1  2  3  4  5  6  7  8  9  10  20  19  14  13  12  18  17  16  22  15  

vector最后的元素为:15
删除vector最后的元素:
打印向量
1  2  3  4  5  6  7  8  9  10  20  19  14  13  12  18  17  16  22  

vector最后的元素为:22
删除vector最后的元素:
打印向量
1  2  3  4  5  6  7  8  9  10  20  19  14  13  12  18  17  16  

向量是否为空,1为空，0为非空:0
vector首部的元素为:1
不能用vec.pop_front()删除vector首部的元素:
打印向量
1  2  3  4  5  6  7  8  9  10  20  19  14  13  12  18  17  16  

第三个元素为:3
第5个元素为:5
改变向量vec的第3个第5个元素
打印向量
1  2  33  4  99  6  7  8  9  10  20  19  14  13  12  18  17  16  

7  8  9  10  20  19  14  13  12  18  17  16  
找到 7 了:7
反转并打印向量
打印向量
16  17  18  12  13  14  19  20  10  9  8  7  6  99  4  33  2  1  

排序并打印向量
打印向量
1  2  4  6  7  8  9  10  12  13  14  16  17  18  19  20  33  99  

向量和为:308
清空向量
vector的容量大小为:0

*/
