/*************************************************************************
>> File Name: C_struct.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
>> Created Time: 2021年01月10日 星期日 00时40分10秒
>> 此程序的功能是：
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

char *s_gets(char *st, int n);
#define MAXTITL 41 /* maximum length of title + 1         */
#define MAXAUTL 31 /* maximum length of author's name + 1 */
#define MAXBKS 100
#define LEN 20
#define FUNDLEN 50
#define SLEN 81

typedef struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
} FUND;
typedef struct names
{ // first structure
    char first[LEN];
    char last[LEN];
} NAME;
typedef struct namect
{
    char *fname; // using pointers
    char *lname;
    int letters;
} NAMES;
typedef struct guy
{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
} GUY;

typedef struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float price;
} BOOK;

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是NULL,
            *find = '\0';        // 此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}

double sum(const struct funds *money)
{
    return (money->bankfund + money->savefund);
}

double sum1(struct funds moolah)
{
    return (moolah.bankfund + moolah.savefund);
}
void getinfo(struct namect *pst)
{
    char temp[SLEN];
    printf("Please enter your first name.\n");
    s_gets(temp, SLEN);
    // allocate memory to hold name
    pst->fname = (char *)malloc(strlen(temp) + 1);
    // copy name to allocated memory
    strcpy(pst->fname, temp);
    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pst->lname = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) +
                   strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
    printf("%s %s, your name contains %d letters.\n",
           pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect *pst)
{
    free(pst->fname);
    free(pst->lname);
}
int main(int argc, char *argv[])
{
    BOOK library; /* declare library as a book variable  */
    printf("*************************简单示例************************.\n");
    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL); /* access to the title portion         */
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.price);
    printf("%s by %s: $%.2f\n", library.title,
           library.author, library.price);
    printf("%s: \"%s\" ($%.2f)\n", library.author,
           library.title, library.price);
    printf("Done.\n");

    printf("*************************指定初始化器************************.\n");
    BOOK gift =
        {
            .price = 29.99,
            .author = "chenjj",
            .title = "one dream"};

    printf("%s: \"%s\" ($%.2f)\n", gift.author, gift.title, gift.price);
    printf("*************************结构数组************************.\n");
    BOOK librarys[MAXBKS]; /* array of book structures */
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(librarys[count].title, MAXTITL) != NULL && librarys[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(librarys[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &librarys[count++].price);
        while (getchar() != '\n')
            continue; /* clear input line         */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", librarys[index].title,
                   librarys[index].author, librarys[index].price);
    }
    printf("*************************结构指针************************.\n");
    struct guy fellow[2] = {
        {{"Ewen", "Villard"},
         "grilled salmon",
         "personality coach",
         68112.00},
        {{"Rodney", "Swillbelly"},
         "tripe",
         "tabloid editor",
         432400.00}};
    struct guy *him; /* here is a pointer to a structure */

    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0]; /* tell the pointer where to point  */
    printf("pointer #1: %p #2: %p\n", him, him + 1);
    printf("him->income is $%.2f: (*him).income is $%.2f\n",
           him->income, (*him).income);
    him++; /* point to the next structure      */
    printf("him->favfood is %s:  him->handle.last is %s\n",
           him->favfood, him->handle.last);

    printf("*************************传递结构的地址************************.\n");
    FUND stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94};

    printf("Stan has a total of $%.2f.\n", sum(&stan));

    /*
    sum()函数使用指向funds结构的指针（money）作为它的参数。把地址&stan传递给该函数，使得指针money指向结构变量stan。然后通过->运算符获取stan.bankfund和stan.savefund的值。由于该函数不能改变指针所指向值的内容，所以把money声明为一个指向const的指针。

    虽然该函数并未使用其他成员，但是也可以访问它们。注意，必须使用&运算符来获取结构的地址。和数组名不同，结构变量名不是其地址的别名。

    现在的C允许把一个结构赋值给另一个结构，但是数组不能这样做。也就是说，如果n_data和o_data都是相同类型的结构，现在的C（包括ANSI C），函数不仅能把结构本身作为参数传递，还能把结构作为返回值返回。把结构作为函数参数可以把结构的信息传送给函数；把结构作为返回值的函数能把结构的信息从被调函数传回主调函数。结构指针也允许这种双向通信，因此可以选择任一种方法来解决编程问题。
    */

    FUND stan1 = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94};

    printf("Stan1 has a total of $%.2f.\n", sum1(stan1));

    printf("************************** 结构、指针和malloc()************************\n");
    NAMES persoN;

    getinfo(&persoN);
    makeinfo(&persoN);
    showinfo(&persoN);
    cleanup(&persoN);

    printf("*************************把结构内容保存到文件中**********************\n");

    BOOK Library[MAXBKS];
    count = 0;
    int filecount;
    FILE *pbooks;
    int size = sizeof(BOOK);

    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("无法打开 book.dat 文件...\n", stderr);
        exit(1);
    }

    rewind(pbooks); /* go to start of file     */
    while (count < MAXBKS && fread(&Library[count], sizeof(BOOK), 1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", Library[count].title, Library[count].author, Library[count].price);
        count++;
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("请输入书名：\n");
    puts("输入Enter以结束：\n");
    while (count < MAXBKS && s_gets(Library[count].title, MAXTITL) != NULL && Library[count].title[0] != '\0')
    {
        puts("请输入作者：\n");
        s_gets(Library[count].author, MAXAUTL);
        puts("请输入价格：\n");
        scanf("%f", &Library[count++].price);
        while (getchar() != '\n')
            continue; /* clear input line  */
        if (count < MAXBKS)
            puts("请输入下一个书名：\n");
    }

    if (count > 0)
    {
        puts("以下是你输入的书籍信息：");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", Library[index].title, Library[index].author, Library[index].price);
        fwrite(&Library[filecount], sizeof(BOOK), count - filecount, pbooks);
    }
    else
        puts("没书吗？太糟糕了.\n");

    puts("Bye.......\n");
    fclose(pbooks);

    printf("************************结束*************************.\n");
    return 0;
}
