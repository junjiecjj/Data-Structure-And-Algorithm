/*************************************************************************
>> File Name: C_bit.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
>> Created Time: 2021年01月10日 星期日 22时27分49秒
>> 此程序的功能是：C语言中的位操作


1．二进制反码或按位取反：～，一元运算符～把1变为0，把0变为1。如下例子所示：
~(10011010)    //表达式
01100101     //结果

2．按位与：&二元运算符&通过逐位比较两个运算对象，生成一个新值。对于每个位，只有两个运算对象中相应的位都为1时，结果才为1（从真/假方面看，只有当两个位都为真时，结果才为真）。因此，对下面的表达式求值：
(10010011) & （00111101）  //表达式
(0001001)        //结果
按位与运算符常用于掩码（mask）。所谓掩码指的是一些设置为开（1）或关（0）的位组合。要明白称其为掩码的原因，先来看通过&把一个量与掩码结合后发生什么情况。例如，假设定义符号常量MASK为2（即，二进制形式为00000010），只有1号位是1，其他位都是0

3．按位或：|二元运算符|，通过逐位比较两个运算对象，生成一个新值。对于每个位，如果两个运算对象中相应的位为1，结果就为1（从真/假方面看，如果两个运算对象中相应的一个位为真或两个位都为真，那么结果为真）。因此，对下面的表达式求值：
(10010011) & （00111101）  //表达式
(10111111)        //结果
有时，需要打开一个值中的特定位，同时保持其他位不变。例如，一台IBM PC通过向端口发送值来控制硬件。例如，为了打开内置扬声器，必须打开1号位，同时保持其他位不变。这种情况可以使用按位或运算符（|）。

4．按位异或：^二元运算符^逐位比较两个运算对象。对于每个位，如果两个运算对象中相应的位一个为1（但不是两个为1），结果为1（从真/假方面看，如果两个运算对象中相应的一个位为真且不是两个为同为1，那么结果为真）。因此，对下面表达式求值：
(10010011) & （00111101）  //表达式
(10101110)        //结果
切换位指的是打开已关闭的位，或关闭已打开的位。可以使用按位异或运算符（^）切换位。也就是说，假设b是一个位（1或0），如果b为1，则1^b为0；如果b为0，则1^b为1。另外，无论b为1还是0，0^b均为b。因此，如果使用^组合一个值和一个掩码，将切换该值与MASK为1的位相对应的位，该值与MASK为0的位相对应的位不变。要切换flags中的1号位.

移位运算符
1．左移：<<左移运算符（<<）将其左侧运算对象每一位的值向左移动其右侧运算对象指定的位数。左侧运算对象移出左末端位的值丢失，用0填充空出的位置。下面的例子中，每一位都向左移动两个位置：
(10001010) <<2 //表达式
(00101000)    //结果值


2．右移：>>右移运算符（>>）将其左侧运算对象每一位的值向右移动其右侧运算对象指定的位数。左侧运算对象移出右末端位的值丢。对于无符号类型，用0填充空出的位置；对于有符号类型，其结果取决于机器。空出的位置可用0填充，或者用符号位（即，最左端的位）的副本填充：

（10001010） >>2    //表达式，有符号值
(00100010)            //在某些系统中的结果值
(10001010) >>2    // 表达式，有符号值
(11100010)            //在另一些些系统中的结果值


位字段：
通常，把位字段作为一种更紧凑存储数据的方式。例如，假设要在屏幕上表示一个方框的属性。为简化问题，我们假设方框具有如下属性：·方框是透明的或不透明的；·方框的填充色选自以下调色板：黑色、红色、绿色、黄色、蓝色、紫色、青色或白色；·边框可见或隐藏；·边框颜色与填充色使用相同的调色板；·边框可以使用实线、点线或虚线样式。可以使用单独的变量或全长（full-sized）结构成员来表示每个属性，但是这样做有些浪费位。例如，只需1位即可表示方框是透明还是不透明；只需1位即可表示边框是显示还是隐藏。8种颜色可以用3位单元的8个可能的值来表示，而3种边框样式也只需2位单元即可表示。总共10位就足够表示方框的5个属性设置。

一种方案是：一个字节存储方框内部（透明和填充色）的属性，一个字节存储方框边框的属性，每个字节中的空隙用未命名字段填充。struct box_props声明如代码：
加上未命名的字段，该结构共占用16位。如果不使用填充，该结构占用10位。但是要记住，C以unsigned int作为位字段结构的基本布局单元。因此，即使一个结构唯一的成员是1位字段，该结构的大小也是一个unsigned int类型的大小，unsigned int在我们的系统中是32位。另外，以上代码假设C99新增的_Bool类型可用，在stdbool.h中，bool是_Bool的别名。对于opaque成员，1表示方框不透明，0表示透明。show_border成员也用类似的方法。对于颜色，可以用简单的RGB（即red-green-blue的缩写）表示。这些颜色都是三原色的混合。显示器通过混合红、绿、蓝像素来产生不同的颜色。在早期的计算机色彩中，每个像素都可以打开或关闭，所以可以使用用1位来表示三原色中每个二进制颜色的亮度。常用的顺序是，左侧位表示蓝色亮度、中间位表示绿色亮度、右侧位表示红色亮度。表15.3列出了这8种可能的组合。fill_color成员和border_color成员可以使用这些组合。最后，border_style成员可以使用0、1、2来表示实线、点线和虚线样式。

下面的程序使用box_props结构，该程序用#define创建供结构成员使用的符号常量。注意，只打开一位即可表示三原色之一。其他颜色用三原色的组合来表示。例如，紫色由打开的蓝色位和红色位组成，所以，紫色可表示为BLUE|RED。
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <sys/socket.h>
#include <stddef.h>
#include <locale.h>
#include <time.h>
#include <complex.h>

//宏定义布尔类型
#define BOOL int
#define TRUE 1
#define FALSE 0

/* line styles     */
#define SOLID 0
#define DOTTED 1
#define DASHED 2
/* primary colors  */
#define BLUE 4
#define GREEN 2
#define RED 1
/* mixed colors    */
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char *colors[8] = {"black", "red", "green", "yellow",
                         "blue", "magenta", "cyan", "white"};

//该程序要注意几个要点。首先，初始化位字段结构与初始化普通结构的语法相同：
struct box_props
{
    BOOL opaque : 1; // or unsigned int (pre C99)
    unsigned int fill_color : 3;
    unsigned int : 4;
    BOOL show_border : 1; // or unsigned int (pre C99)
    unsigned int border_color : 3;
    unsigned int border_style : 2;
    unsigned int : 2;
};

void show_settings(const struct box_props *pb);
void show_settings(const struct box_props *pb)
{
    printf("Box is %s.\n",
           pb->opaque == TRUE ? "opaque" : "transparent");

    //另外，switch语句中也可以使用位字段成员，甚至还可以把位字段成员用作数组的下标：
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n",
           pb->show_border == TRUE ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ");
    switch (pb->border_style)
    {
    case SOLID:
        printf("solid.\n");
        break;
    case DOTTED:
        printf("dotted.\n");
        break;
    case DASHED:
        printf("dashed.\n");
        break;
    default:
        printf("unknown type.\n");
    }
}
int main(int argc, char *argv[])
{
    /* create and initialize box_props structure */
    struct box_props box = {TRUE, YELLOW, TRUE, GREEN, DASHED};

    printf("Original box settings:\n");
    show_settings(&box);

    box.opaque = FALSE;

    //类似地，也可以给位字段成员赋值：
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("\nModified box settings:\n");
    show_settings(&box);

    return 0;
}
