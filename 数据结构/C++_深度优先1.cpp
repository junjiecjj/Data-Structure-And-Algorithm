/*************************************************************************
>> File Name: C++_深度优先1.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.06.12
************************************************************************/

#include<iostream>
using namespace std;

#include<limits.h>
using namespace std;
int sum = 0;
bool visited[6] = { false };
const int map[6][6]=
{ {0,0,0,0,0,0}
,{0,0,1,1,INT_MAX ,1}
,{0,1,0,INT_MAX ,1,INT_MAX }
,{0,1,INT_MAX ,0,INT_MAX ,1}
,{0, INT_MAX ,1,INT_MAX,0,INT_MAX }
,{0,1,INT_MAX ,1,INT_MAX ,0} };
void DFS(int step)
{
	cout << step << " ";   //访问
	sum++;
	if (sum == 5)return;  //结束条件
	for (int i = 1;i <= 5;i++)   //从1开始尝试连通该节点的节点
	{
		if (map[step][i] == 1 && visited[i] == false)  //如果满足条件
		{
			visited[i] = true;
			DFS(i);   //从i号节点开始遍历
		}
	}
	return;//对图的遍历回溯应该是在节点周围不再连通的时候回溯，所以return放在循环结束的时候
}
int  main()
{
	visited[1] = true;//从1开始走，所以初始化一下
	DFS(1);
    return 0;
}
