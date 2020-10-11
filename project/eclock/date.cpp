/*
   显示当前日期
   作者：WonderBoy
   最后修改日期：2020-10-11
*/
#include <cstdio>
#include <cstring>
#include <ctime>
#include <windows.h>

int main() {
    while (1) {
        time_t nowtime;
        struct tm *p;
        char tmp[50];
        time(&nowtime);
        p = localtime(&nowtime);
        snprintf(tmp, 50, "%d-%d-%d %02d:%02d:%02d", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
        printf("%s", tmp);
        Sleep(1000);
        for (unsigned int i = 1; i <= strlen(tmp); i++)
            printf("\b");
    }
    return 0;
}