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

    cout << "字符串不支持string.push_front" << endl;

    //S.push_front('M');                        //string不支持string.push_front()
    cout << S << endl;
    cout << "字符串最后的元素为:" << S.back() << endl;
    cout << "字符串开始的元素为:" << S.front() << endl;
    cout << "删除字符串S最后的元素:" << endl;
    S.pop_back();

    cout << "字符串不支持string.pop_front" << endl;
    //S.pop_front()            //string不支持string.pop_front()
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

    cout << "清空字符串" << endl;
    S.clear();
    cout << S << endl;
    //cout << stoi(argv[1]) <<  endl;
    return 0;
}
/*
 输出为:
字符串S的元素个数为:21
字符串S的最大元素个数为:9223372036854775807
chen junjie!!!, hello
字符串不支持string.push_front
chen junjie!!!, helloNP
字符串最后的元素为:P
字符串开始的元素为:c
删除字符串S最后的元素:
字符串不支持string.pop_front
chen junjie!!!, helloN
chen junjie!!!, helloN
c  h  e  n     j  u  n  j  i  e  !  !  !  ,     h  e  l  l  o  N  
字符串第7个元素为:u
字符串第8个元素为:n
通过S.at(n)和S[n]改变S
chen juPjie!!!, helloN
chen juPQie!!!, helloN
清空字符串
 */
