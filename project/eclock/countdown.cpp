/*
   高考倒计时
   作者：WonderBoy
   最后修改日期：2020-10-11
*/
#include <cstdio>
#include <cstring>
#include <ctime>
#include <windows.h>

const int TMON = 6, TDAY = 7;

int getMonDays(int mon)
{
    if (mon == 2)
        return 28;
    if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
        return 31;
    return 30;
}

int getDays(int year, int mon, int day)
{
    int days = 0;
    if (year == 2020)
    {
        days = getMonDays(mon) - day;
        for (int i = mon + 1; i <= 12; i++)
            days += getMonDays(i);
        days += getDays(2021, 1, 1) + 1;
    }
    else if (year == 2021)
    {
        if (mon == TMON)
        {
            days = TDAY - day;
        }
        else
        {
            days = getMonDays(mon) - day;
            for (int i = mon + 1; i <= TMON - 1; i++)
                days += getMonDays(i);
            days += TDAY;
        }
    }
    return days;
}

float getPartDay(int hour, int min, int sec)
{
    int s = hour * 3600 + min * 60 + sec;
    return 1 - (float)s / 86400;
}

int main()
{
    while (1)
    {
        time_t nowtime;
        struct tm *p;
        char tmp[50];
        time(&nowtime);
        p = localtime(&nowtime);
        snprintf(tmp, 50, "%.5f Days", getDays(p->tm_year + 1900, p->tm_mon + 1, p->tm_mday) + getPartDay(p->tm_hour, p->tm_min, p->tm_sec));
        printf("%s", tmp);
        Sleep(500);
        for (unsigned int i = 1; i <= strlen(tmp); i++)
            printf("\b");
    }

    return 0;
}