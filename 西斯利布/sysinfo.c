#include <stdio.h>
#include <sys/sysinfo.h>
int main(int argc, char *agrv[])
{
    struct sysinfo s_info;
    int error;
    error = sysinfo(&s_info);
    printf("\n code error = %d \n", error);
    printf("s_info.uptime = %lu\n,
    s_info.loads[0] = %lu\n,
    s_info.loads[1] = %lu\n,
    s_info.loads[2] = %lu\n,
    s_info.",);
    printf("hhh");
    return 0;
}
