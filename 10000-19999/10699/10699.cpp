// 10699 오늘 날짜
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main(){
    time_t t;
    tm *pt;

    time(&t);
    pt = localtime(&t);
    if (pt->tm_mon < 10){
        if (pt->tm_mday < 10){
            printf("%d-0%d-0%d", pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday);
        }
        else {
            printf("%d-0%d-%d", pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday);
        }
    }
    else {
        if (pt->tm_mday < 10){
            printf("%d-%d-0%d", pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday);
        }
        else {
            printf("%d-%d-%d", pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday);
        }
    }
    return 0;
}
