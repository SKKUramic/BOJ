// 1924 2007년
// https://www.acmicpc.net/problem/1924
#include <stdio.h>

int month_list[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	int month, day, sum = 0;
	scanf("%d %d", &month, &day);
	for (int i = 1; i < month; i++){
		sum += month_list[i];
	}
	sum += day;
	sum--;
	switch (sum % 7){
		case 0:
			printf("MON");
			break;
		case 1:
			printf("TUE");
			break;
		case 2:
			printf("WED");
			break;
		case 3:
			printf("THU");
			break;
		case 4:
			printf("FRI");
			break;
		case 5:
			printf("SAT");
			break;
		case 6:
			printf("SUN");
			break;
		default:
			break;
	}
}