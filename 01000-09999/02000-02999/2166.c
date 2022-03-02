// 2166 다각형의 면적
// https://www.acmicpc.net/problem/2166
#include <stdio.h>

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
	long long int ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	return ccw;
}

long long point_list[10001][2] = {0, };

int main(){
	int point;
	long long Px, Py, area = 0;
	scanf("%d", &point);
	for (int p = 0; p < point; p++){
		scanf("%lld %lld", &point_list[p][0], &point_list[p][1]);
	}
	Px = point_list[0][0]; Py = point_list[0][1];
	for (int p = 1; p < point - 1; p++){
		area += CCW(Px, Py, point_list[p][0], point_list[p][1], point_list[p + 1][0], point_list[p + 1][1]);
	}
	if (area < 0){area = -area;}
	if (area % 2 == 1){
		printf("%lld.5", area / 2);
	}
	else {
		printf("%lld.0", area / 2);
	}
}