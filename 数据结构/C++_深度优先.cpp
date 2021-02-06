/*************************************************************************
>> File Name: C++_深度优先.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.06.12


二维数组地图的寻路最短步数
(下标从1开始)


       y

    0 0 1 0

    0 0 0 0

x   0 0 1 0

    0 1 0 0

    0 0 0 1

这样的一个5*4的矩阵，1代表路障，0可以走，从（1，1）出发，到（4，3）的位置
(0,0)在左上角, 
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>


int Map[6][5] = {0};
bool visited[6][5] = {false};
int Min = 99999;

void DFS(int x, int y, int step)
{
    int tx = 0, ty = 0;
    int Next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    if(x == 4 && y == 3)
    {
        if(step < Min)
        {
            Min = step;
            return;
        }
    }

    for(int k = 0; k < 4; ++k)
    {
        tx = x + Next[k][0];
        ty = y + Next[k][1];

        if(tx < 1 || tx > 5 || ty < 1 || ty > 4)
            continue;
        if(visited[tx][ty] == false && Map[tx][ty] == 0)
        {
            visited[tx][ty] = true;
            DFS(tx, ty, step + 1);
            visited[tx][ty] = false;
        }
    }
    return;
}


int main(int argc , char *argv[])
{
    Map[1][3] = 1;
    Map[3][3] = 1;
    Map[4][2] = 1;
    Map[5][4] = 1;
    visited[1][1] = true;
    DFS(1,1,0);
    cout << Min << endl;
}
