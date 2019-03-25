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
#include<cstring>
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
    cout << "\n\n";
}

int main(int argc, char *argv[])
{
    string S = "chen junjie!!!, hello";
    cout << "字符串S的元素个数为:" << S.size() << endl;
    cout << "字符串S的最大元素个数为:" << S.max_size() << endl;

    cout << "打印字符串\n";
    cout << S << endl;
    S.push_back('N');
    S.push_back('P');

    cout << "字符串不支持string.push_front\n" << endl;
    //S.push_front('M');                        //string不支持string.push_front()

    cout << "打印字符串\n";
    cout << S << endl;
    cout << "字符串最后的元素为:" << S.back() << endl;
    cout << "字符串开始的元素为:" << S.front() << endl;
    cout << "删除字符串S最后的元素:" << endl;
    S.pop_back();

    cout << "字符串不支持string.pop_front" << endl;
    //S.pop_front()            //string不支持string.pop_front()

    cout << "打印字符串\n";
    show(S);

    cout << "字符串第7个元素为:" << S.at(6) << endl;
    cout << "字符串第8个元素为:" << S[7] << endl;

    cout << "通过S.at(n)和S[n]改变S" << endl;
    S.at(7) = 'P';
    cout << S << endl;

    S[8] = 'Q';
    cout << S << endl;

    auto result = find(S.cbegin(), S.cend(), 'j');
    for(auto i = result; i != S.end(); i++)
        cout << *i;
    cout << endl;
    cout << "找到 'j' 了:" << *result << endl;

    cout << "反转并打印字符串\n";
    reverse(S.begin(),S.end());
    show(S);

    cout << "排序并打印队列\n";
    sort(S.begin(),S.end());
    show(S);

    cout << "清空字符串" << endl;
    S.clear();
    cout << S << endl;
    //cout << stoi(argv[1]) <<  endl;
        
    string S1 = "chen&jun&jie, hello!!!";
    string S2 = "I am fear@@@";
    const char *cp = "wang yin ##!";
    cout << "字符串S1:" << S1 <<endl;
    cout << "字符串S2:" << S2 <<endl;
    cout << "字符串cp:" << cp <<endl;

    S1.insert(5,"dick , !");
    cout << "字符串S1:" << S1 <<endl;
    
    S1.insert(5,S2,0,3);
    cout << "字符串S1:" << S1 <<endl;
    

    S1.insert(5, cp, 6);
    cout << "字符串S1:" << S1 <<endl;

    S1.insert(5, cp);
    cout << "字符串S1:" << S1 <<endl;

    S1.insert(5, 3, '%');
    cout << "字符串S1:" << S1 <<endl;

    S1.replace(5, 3, "*****");
    cout << "字符串S1:" << S1 <<endl;

    S1.erase(5,3);
    cout << "字符串S1:" << S1 <<endl;

    int i = 1234 ;
    cout << "int : i = " << i << endl;

    string S3 = to_string(i);
    cout << "string S3 = " << S3 << endl;

    double d = stod(S3);
    cout << "double d = " << d << endl;

    char S4[20] = "hello world";
    char S5[20] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    char S6[20] = {'h','e','l','l','o',' ','w','o','r','l','d'};
    char S7[] = "hello\0 world";
    char S8[] = {'h','e','l','l','o','\0',' ','w','o','r','l','d','\0'};
    char S9[] = {'h','e','l','l','o','\0',' ','w','o','r','l','d',};
    char S10[] = {'h','e','l','l','o',' ','w','o','r','l','d',};//strlen(S10)产生未定义的结果，因为S10不是以'\0'结尾，strlen可能一直向前查找直到遇到空字符
    const char *S11 = "hello world";
    string S12 = "hello world";
    string S13 = {'h','e','l','l','o',' ','w','o','r','l','d'};

    printf("strlen(S4) = %zd , strlen(S5) = %zd , strlen(S6) = %zd , strlen(S7) = %zd , strlen(S8) = %zd , strlen(S9) = %zd , strlen(S10) = %zd , strlen(S11) = %zd\n",
            strlen(S4),strlen(S5),strlen(S6),strlen(S7),strlen(S8),strlen(S9), strlen(S10),strlen(S11));

    printf("sizeof(S4) = %zd , sizeof(S5) = %zd , sizeof(S6) = %zd , sizeof(S7) = %zd , sizeof(S8) = %zd, sizeof(S9) = %zd , sizeof(S10) = %zd , sizeof(S11) = %zd\n",
            sizeof(S4),sizeof(S5),sizeof(S6),sizeof(S7),sizeof(S8), sizeof(S9), sizeof(S10),sizeof(S11));

    //cout << "strlen(S9) = " << strlen(S9) << endl;         
    //  strlen()只能以char *作为参数,不能以类型作为参数,该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符'\0'。返回的长度大小不包括'\0'。
    //  c/c++ strlen(str)和str.length()和str.size()都可以求字符串长度。
    //  其中str.length()和str.size()是用于求string类对象长度的成员函数
    //  strlen(str)是用于求字符数组的长度，其参数是char*

    cout << "S12.size() = " << S12.size() << endl;
    cout << "sizeof(S12) = " << sizeof(S12) << endl;

    //cout << "strlen(S13) = " << strlen(S13) << endl;
    cout << "S13.size() = " << S13.size() << endl;
    cout << "sizeof(S13) = " << sizeof(S13) << endl;
    return 0;

    return 0;
}
/*
 输出为:


字符串S的元素个数为:21
字符串S的最大元素个数为:9223372036854775807
打印字符串
chen junjie!!!, hello
字符串不支持string.push_front

打印字符串
chen junjie!!!, helloNP
字符串最后的元素为:P
字符串开始的元素为:c
删除字符串S最后的元素:
字符串不支持string.pop_front
打印字符串
chen junjie!!!, helloN


字符串第7个元素为:u
字符串第8个元素为:n
通过S.at(n)和S[n]改变S
chen juPjie!!!, helloN
chen juPQie!!!, helloN
juPQie!!!, helloN
找到 'j' 了:j
反转并打印字符串
Nolleh ,!!!eiQPuj nehc


排序并打印队列
  !!!,NPQceeehhijllnou


清空字符串

字符串S1:chen&jun&jie, hello!!!
字符串S2:I am fear@@@
字符串cp:wang yin ##!
字符串S1:chen&dick , !jun&jie, hello!!!
字符串S1:chen&I adick , !jun&jie, hello!!!
字符串S1:chen&wang yI adick , !jun&jie, hello!!!
字符串S1:chen&wang yin ##!wang yI adick , !jun&jie, hello!!!
字符串S1:chen&%%%wang yin ##!wang yI adick , !jun&jie, hello!!!
字符串S1:chen&*****wang yin ##!wang yI adick , !jun&jie, hello!!!
字符串S1:chen&**wang yin ##!wang yI adick , !jun&jie, hello!!!
int : i = 1234
string S3 = 1234
double d = 1234
strlen(S4) = 11 , strlen(S5) = 11 , strlen(S6) = 11 , strlen(S7) = 5 , strlen(S8) = 5 , strlen(S9) = 5 , strlen(S10) = 16 , strlen(S11) = 11
sizeof(S4) = 20 , sizeof(S5) = 20 , sizeof(S6) = 20 , sizeof(S7) = 13 , sizeof(S8) = 13, sizeof(S9) = 12 , sizeof(S10) = 11 , sizeof(S11) = 8
S12.size() = 11
sizeof(S12) = 32
S13.size() = 11
sizeof(S13) = 32


 */
