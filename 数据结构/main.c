#include<stdio.h>
#include<signal.h>
#include<time.h>
#include<string.h>
#include <unistd.h>

int a[] = {0,0,0, 1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int main()
{
	int index_start = 0;
	int index_end = 0;
	int len = 1;
	int tmp = 0;
	int start = 0;
	int end = 0;
	int i = 0;
	int lenOfA = sizeof(a)/sizeof(int);
	printf("len of a = %d\n",lenOfA);
	for(int i = 0; i < lenOfA; ++i)
    {
        if(a[i] == 0)
        {
            continue;
        }
        else
        {
            index_start = i;

        }
    }


	printf("len = %d, start = %d, end = %d\n",len, start, end);

    return 0;

}





