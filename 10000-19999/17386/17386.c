// 17386 선분 교차 1
// https://www.acmicpc.net/problem/17386
// CCW 알고리즘을 이용한 문제입니다.
#include <stdio.h>

int CCW(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3){
	long long int ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	if (ccw < 0){return -1;}
	else if (ccw > 0) {return 1;}
	else {return 0;} // 이 문제에서는 사용되지 않습니다.
}

int main(){
	int CCW12_3, CCW12_4, CCW34_1, CCW34_2;
	long long int x1, x2, x3, x4, y1, y2, y3, y4;
	long long int A12, B12, C12, A34, B34, C34;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);
	CCW12_3 = CCW(x1, y1, x2, y2, x3, y3);
	CCW12_4 = CCW(x1, y1, x2, y2, x4, y4);
	CCW34_1 = CCW(x3, y3, x4, y4, x1, y1);
	CCW34_2 = CCW(x3, y3, x4, y4, x2, y2);
	if (CCW12_3 * CCW12_4 == -1 && CCW34_1 * CCW34_2 == -1){
		printf("1");
	}
	else {
		printf("0");
	}
	return 0;
}