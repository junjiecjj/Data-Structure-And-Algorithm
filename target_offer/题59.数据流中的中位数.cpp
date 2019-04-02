/*************************************************************************
>> File Name: 数据流中的中位数.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02

题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
使用GetMedian()方法获取当前读取数据的中位数。
************************************************************************/

#include<iostream>
using namespace std;
#include<queue>

class Solution
{
    public:
        void Insert(int num)
        {
            if(Max.size() == Min.size())
            {
                if(Max.size() != 0 && num < Max.top())
                {
                    Max.push(num);
                    num = Max.top();
                    Max.pop();
                }

                Min.push(num);
            }
            else
            {
                if(Min.top() < num)
                {
                    Min.push(num);
                    num = Min.top();
                    Min.pop();
                }
                Max.push(num);
            }
        }

        void show(priority_queue<int> pq)
        {
            while(pq.size() != 0)
            {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout << "\n\n";
        }
        void show1(priority_queue<int,vector<int>, greater<int>> pq)
        {
            while(pq.size() != 0)
            {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout << "\n\n";
        }
        double GetMedian()
        {
            return Max.size() == Min.size() ? (Max.top()+Min.top())/2.0 : Min.top();
        }

    public:
        priority_queue<int, vector<int>, less<int>> Max;
        priority_queue<int, vector<int>, greater<int>> Min;

};

int main()
{

    Solution test;
    test.Insert(1);
    test.Insert(2);
    test.Insert(3);
    test.Insert(4);
    test.Insert(8);
    test.Insert(5);
    test.Insert(7);
    test.Insert(9);
    test.Insert(14);
    test.Insert(19);
    test.Insert(18);
    test.Insert(16);
    test.Insert(15);
    test.Insert(13);
    test.Insert(12);
    test.Insert(20);
    test.Insert(30);

    test.show(test.Max);
    test.show1(test.Min);

    cout << test.GetMedian() << endl;
    return 0;
}
