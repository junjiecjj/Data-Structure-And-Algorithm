#include <stdio.h>
#include <stdlib.h>

//extern int roll_count;

int roll_count = 0; /* 外部链接 */

int roll_n_dice(int dice, int sides);

static int rollem(int sides) /* 该文件属于该私有文件*/
{
    int roll;

    roll = rand() % sides + 1;
    ++roll_count; /* 计算函数被调次数 */

    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }

    for (d = 0; d < dice; d++)
        total += rollem(sides);

    return total;
}
