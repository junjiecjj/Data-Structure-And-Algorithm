/*************************************************************************
>> File Name: 圆圈中最后剩下的数.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02

题目描述
0,1,2...n-1这n个数排成一圈,从数字0开始数,每次从这个圈里删除第m个数,求出这个圆圈最后剩下的最后一个数字
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
#include<list>

class Solution
{
    public:
        int LastRemaining_Solution(int n, int m)
        {
            if(n < 1 || m < 1)
                return -1;
            int last = 0;
            for(int i = 2; i <= n; i++)
                last = (last + m)%i;

            return last;
        }

        int LastRemaining_Solution1(int n, int m)
        {
            if(n < 1 || m < 1)
                return -1;
            vector<int> res;
            for(int i= 0; i < n; i++)
                res.push_back(i);
            int k = 0;
            while(res.size() > 1)
            {
                k = (k + m - 1)% res.size();
                res.erase(res.begin() + k);
            }
            return res[0];
        }
        int LastRemaining_Solution2(int n, int m)
        {
            if(n<=0||m<=0)
                return -1;//非负的int型的异常判断要设置为返回-1
            list<int> num;//list型的容器，容器的一种
            for(int i=0;i<n;i++)
                num.push_back(i);
            list<int>::iterator cur=num.begin();//迭代器生成的都是指针形式的
            while(num.size()>1)//当最后size为1的时候，就停止循环了
            {
                for(int i=1;i<m;i++)//为了得到待删除的点
                {
                    cur++;
                    if(cur==num.end())//list毕竟不是环，如果指向末尾了，需要让它重新指向开头，这样来达到模拟一个环的作用
                        cur=num.begin();
                }
                list<int>::iterator next=(++cur);//赋值的时候先自加，再赋值，因为我想要保存下来cur的值，而cur是一个类似指针的形式
                                             //所以就新建一个迭代器
                if(next==num.end())//这里也要考虑到模拟环的作用
                    next=num.begin();
                cur--;//cur之前自加了，这里要让它变回原来那个待删除的点
                num.erase(cur);//直接删除这个类似指针的东西，就可以达到删除的目的
                cur=next;
            }
            return *(cur);//返回的要是值，所以加*
    }
};
