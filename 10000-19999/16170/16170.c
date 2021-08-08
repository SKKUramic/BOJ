// 16170 오늘의 날짜
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now_time;
    struct tm *t;
   	now_time = time(NULL);
    t = gmtime(&now_time);
    printf("%d\n%d\n%d", t->tm_year + 1900, t->tm_mon+1, t->tm_mday);
}