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

void Show(const string S)
{
    auto it  = S.begin();
    for(; it != S.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

void show(const string S)
{
    cout << S << endl;
}
int main(int argc, char *argv[])
{
    string S = "chen junjie!!!, hello";
    cout << "字符串S的元素个数为:" << S.size() << endl;
    cout << "字符串S的最大元素个数为:" << S.max_size() << endl;
    cout << S << endl;
    S.push_back('N');
    S.push_back('P');
    //S.push_front('M');
    cout << S << endl;
    cout << "字符串最后的元素为:" << S.back() << endl;
    cout << "字符串开始的元素为:" << S.front() << endl;
    cout << "删除字符串S最后的元素:" << endl;
    S.pop_back();
    cout << S << endl;
    show(S);
    Show(S);
    cout << "字符串第7个元素为:" << S.at(6) << endl;
    cout << "字符串第8个元素为:" << S[7] << endl;

    cout << "通过S.at(n)和S[n]改变S" << endl;
    S.at(7) = 'P';
    cout << S << endl;

    S[8] = 'Q';
    cout << S << endl;
    //cout << stoi(argv[1]) <<  endl;
    return 0;
}
